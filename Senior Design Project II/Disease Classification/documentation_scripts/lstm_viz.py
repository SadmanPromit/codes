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
from torchviz import make_dot

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
OUTPUT_DIR = './output/'  # implement later


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
        return self.data[idx].astype(np.float32), int(self.labels[idx])


class LSTM(nn.Module):
    def __init__(self, input_dim, hidden_dim, num_layers, output_dim, dropout_prob=DROPOUT_RATE):
        super(LSTM, self).__init__()
        self.lstm = nn.LSTM(input_dim, hidden_dim, num_layers=num_layers, batch_first=True)
        self.dropout = nn.Dropout(dropout_prob)
        self.fc1 = nn.Linear(hidden_dim, 128)  # Note: No longer multiplied by 2
        self.fc2 = nn.Linear(128, output_dim)

    def forward(self, x):
        # LSTM
        lstm_out, _ = self.lstm(x)
        lstm_out_flat = lstm_out.contiguous().view(lstm_out.size(0), -1)  # Flatten LSTM outputs

        out_fc1 = self.dropout(nn.LeakyReLU()(self.fc1(lstm_out_flat)))
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
    df.to_excel('./output/log_lstm.xlsx', index=False)

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

    with open(f'./output/pm_lstm.txt', 'w') as f:
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
    plt.savefig(f'./output/cm_lstm.png', dpi=600)
    plt.close()
    torch.save(model.state_dict(), f'./output/st_lstm.pth')
    return accuracy


if __name__ == "__main__":
    dummy_input = torch.randn(1, 1, 13)
    input_dim = 13
    hidden_dim = 64
    num_layers = 1
    output_dim = 4
    model = LSTM(input_dim, hidden_dim, num_layers, output_dim)
    out = model(dummy_input)
    dot = make_dot(out, params=dict(list(model.named_parameters())))
    dot.format = 'png'
    dot.attr(dpi='600')
    dot.render("lstm_architecture")