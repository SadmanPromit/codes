import torch
import torch.nn as nn
import torch.optim as optim
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from tqdm import tqdm
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score, confusion_matrix
from torch.utils.data import Dataset, DataLoader
from torch.optim.lr_scheduler import OneCycleLR
from imblearn.over_sampling import ADASYN, SMOTE
import time
import os

# Hyperparameters
SEED = 64
EPOCHS = 1000
LEARNING_RATE = 0.01
DROPOUT_RATE = 0.1
WEIGHT_DECAY = 1e-3
PATIENTS_EPOCH = 10
OVERSAMPLING = "adasyn"

torch.manual_seed(SEED)
torch.cuda.manual_seed_all(SEED)
np.random.seed(SEED)
torch.backends.cudnn.deterministic = True
torch.backends.cudnn.benchmark = False
OUTPUT_DIR = './output/'    # implement later


# This function will reverse map the one-hot-encoded values.
def reverse_map_classes(encoded_labels):
    mapping = {
        1: 'Beta Minor',
        2: 'Beta Major',
        3: 'Alpha Major',
        0: 'Alpha Minor'
    }
    return [mapping[label] for label in encoded_labels]


def initialize_weights(m):
    if isinstance(m, nn.Conv1d):
        nn.init.kaiming_normal_(m.weight.data, nonlinearity='leaky_relu')
        if m.bias is not None:
            nn.init.constant_(m.bias.data, 0)
    elif isinstance(m, nn.Linear):
        nn.init.kaiming_normal_(m.weight.data, nonlinearity='leaky_relu')
        nn.init.constant_(m.bias.data, 0)


def calculate_metrics(true_labels, predictions):
    accuracy = accuracy_score(true_labels, predictions)
    precision = precision_score(true_labels, predictions, average='weighted', zero_division=0)
    recall = recall_score(true_labels, predictions, average='weighted', zero_division=0)
    f1 = f1_score(true_labels, predictions, average='weighted', zero_division=0)
    return accuracy, precision, recall, f1


def load_and_balance_data(method=OVERSAMPLING):
    train = pd.read_csv("./thalBD_train.csv")
    X = train.drop(columns=['Thalassemia Type']).values
    y = train['Thalassemia Type'].values

    if method == "adasyn":
        oversampler = ADASYN(random_state=SEED)
    elif method == "smote":
        oversampler = SMOTE(random_state=SEED)
    else:
        raise ValueError(f"Invalid oversampling method: {method}")

    X_resampled, y_resampled = oversampler.fit_resample(X, y)

    train_balanced = pd.DataFrame(X_resampled, columns=train.columns.drop('Thalassemia Type'))
    train_balanced['Thalassemia Type'] = y_resampled

    val = pd.read_csv("./thalBD_val.csv")

    return train_balanced, val


class ThalassemiaDataset(Dataset):
    def __init__(self, dataframe):
        self.data = dataframe.drop(columns=['Thalassemia Type']).values
        self.labels = dataframe['Thalassemia Type'].values

    def __len__(self):
        return len(self.data)

    def __getitem__(self, idx):
        return self.data[idx].astype(np.float32).reshape(1, 13), int(self.labels[idx])


class CNN(nn.Module):
    def __init__(self, dropout_prob=DROPOUT_RATE):
        super(CNN, self).__init__()
        self.conv1 = nn.Conv1d(1, 32, kernel_size=3, stride=1, padding=1)
        self.conv1x1 = nn.Conv1d(32, 64, kernel_size=1)  # 1x1 convolution to increase the channel size
        self.conv2 = nn.Conv1d(32, 64, kernel_size=3, stride=1, padding=1)
        self.dropout = nn.Dropout(dropout_prob)
        self.fc1 = nn.Linear(64 * 13, 128)
        self.fc2 = nn.Linear(128, 4)

    def forward(self, x):
        # First convolutional layer
        out_conv1 = nn.LeakyReLU()(self.conv1(x))

        # Use 1x1 convolution to match the channels for skip connection
        out_conv1_matched = self.conv1x1(out_conv1)

        # Second convolutional layer with skip connection from the first layer
        out_conv2 = nn.LeakyReLU()(self.conv2(out_conv1) + out_conv1_matched)

        out_conv2_flat = out_conv2.view(out_conv2.size(0), -1)
        out_fc1 = self.dropout(nn.LeakyReLU()(self.fc1(out_conv2_flat)))
        out_fc2 = self.fc2(out_fc1)

        return out_fc2


def train_model(train_loader, val_loader, model, criterion, optimizer, scheduler, n_epochs=EPOCHS):
    best_val_loss = float('inf')
    epochs_without_improvement = 0
    epoch_data = []
    for epoch in tqdm(range(n_epochs)):
        start_time = time.time()
        model.train()
        train_predictions, train_labels = [], []
        for batch_idx, (data, labels) in enumerate(train_loader):
            data, labels = data.float().cuda(), labels.long().cuda()
            optimizer.zero_grad()
            outputs = model(data)
            loss = criterion(outputs, labels)
            loss.backward()
            optimizer.step()

            _, predicted = torch.max(outputs.data, 1)
            train_predictions.extend(predicted.cpu().numpy())
            train_labels.extend(labels.cpu().numpy())

        model.eval()
        val_loss = 0.0
        val_predictions, val_labels = [], []
        with torch.no_grad():
            for data, labels in val_loader:
                data, labels = data.float().cuda(), labels.long().cuda()
                outputs = model(data)
                loss = criterion(outputs, labels)
                val_loss += loss.item()

                _, predicted = torch.max(outputs.data, 1)
                val_predictions.extend(predicted.cpu().numpy())
                val_labels.extend(labels.cpu().numpy())

        train_accuracy, train_precision, train_recall, train_f1 = calculate_metrics(train_labels, train_predictions)
        val_accuracy, val_precision, val_recall, val_f1 = calculate_metrics(val_labels, val_predictions)

        epoch_duration = time.time() - start_time

        epoch_info = {
            'Epoch': epoch + 1,
            'Epoch Duration': epoch_duration,
            'Train Loss': loss.item(),
            'Val Loss': val_loss,
            'Train Accuracy': train_accuracy,
            'Train Precision': train_precision,
            'Train Recall': train_recall,
            'Train F1-Score': train_f1,
            'Val Accuracy': val_accuracy,
            'Val Precision': val_precision,
            'Val Recall': val_recall,
            'Val F1-Score': val_f1
        }

        epoch_data.append(epoch_info)
        scheduler.step()

        if val_loss < best_val_loss:
            best_val_loss = val_loss
            epochs_without_improvement = 0
            # Using val_loader for testing
            test_accuracy = test_model(epoch, model, val_loader)
        else:
            epochs_without_improvement += 1

        # Check for early stopping
        if epochs_without_improvement == PATIENTS_EPOCH:
            break

    # Save to an Excel file instead of a log file
    df = pd.DataFrame(epoch_data)
    df.to_excel('./output/log_cnn.xlsx', index=False)

    return model


def test_model(epoch, model, test_loader):
    model.eval()
    predictions, true_labels = [], []
    with torch.no_grad():
        for data, labels in test_loader:
            data, labels = data.float().cuda(), labels.long().cuda()
            outputs = model(data)
            _, predicted = torch.max(outputs.data, 1)
            predictions.extend(predicted.cpu().numpy())
            true_labels.extend(labels.cpu().numpy())

    # Reverse mapping the one-hot-encoded labels for confusion matrix
    true_labels_mapped = reverse_map_classes(true_labels)
    predictions_mapped = reverse_map_classes(predictions)

    accuracy, precision, recall, f1 = calculate_metrics(true_labels_mapped, predictions_mapped)
    metrics = {'Epoch': epoch + 1, 'Accuracy': accuracy, 'Precision': precision, 'Recall': recall, 'F1-Score': f1}

    with open(f'./output/pm_cnn.txt', 'w') as f:
        for key, value in metrics.items():
            f.write(f'{key}: {value}\n')

    # Define class names for your labels
    classes = ['Alpha Minor', 'Beta Minor', 'Beta Major', 'Alpha Major']

    cm = confusion_matrix(true_labels, predictions)
    plt.figure(figsize=(6, 6))
    plt.imshow(cm, interpolation='nearest', cmap='Blues')
    plt.colorbar()
    plt.title('Confusion Matrix')

    # Add labels to the axes
    tick_marks = np.arange(len(classes))
    plt.xticks(tick_marks, classes, rotation=45)
    plt.yticks(tick_marks, classes)

    # Display the values in the cells
    for i in range(cm.shape[0]):
        for j in range(cm.shape[1]):
            color = "white" if cm[i, j] > cm.max() / 2 else "black"
            plt.text(j, i, format(cm[i, j], "d"), horizontalalignment="center", color=color)

    plt.ylabel('True Label')
    plt.xlabel('Predicted Label')
    plt.tight_layout()  # This ensures that labels do not overlap
    plt.savefig(f'./output/cm_cnn.png', dpi=600)
    plt.close()
    torch.save(model.state_dict(), f'./output/st_cnn.pth')
    return accuracy


def load_saved_model(model_path):
    model = CNN().cuda()
    model.apply(initialize_weights)
    model.load_state_dict(torch.load(model_path))
    return model


if __name__ == "__main__":
    if not os.path.exists(OUTPUT_DIR):
        os.makedirs(OUTPUT_DIR)
    train_balanced, val = load_and_balance_data()

    train_dataset = ThalassemiaDataset(train_balanced)
    val_dataset = ThalassemiaDataset(val)

    train_loader = DataLoader(train_dataset, batch_size=64, shuffle=True)
    val_loader = DataLoader(val_dataset, batch_size=64, shuffle=False)


    model = CNN().cuda()
    criterion = nn.CrossEntropyLoss()
    optimizer = optim.Adam(model.parameters(), lr=LEARNING_RATE, weight_decay=WEIGHT_DECAY)
    scheduler = OneCycleLR(optimizer, max_lr=LEARNING_RATE, steps_per_epoch=len(train_loader), epochs=EPOCHS)

    train_model(train_loader, val_loader, model, criterion, optimizer, scheduler)
