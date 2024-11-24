import torch
import torch.nn as nn
import torchvision.transforms as transforms
import torchvision.datasets as datasets
import torchvision.models as models
from torch.utils.data import DataLoader
import torch.optim as optim
from torch.optim.lr_scheduler import OneCycleLR
from sklearn.metrics import confusion_matrix, accuracy_score, precision_recall_fscore_support
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import itertools
from tqdm import tqdm
import time
import random
import os

# Hyperparameters for 10 Models
DROPOUT_RATES = [0, 0.2, 0.3, 0.4, 0.5]
BATCH_NORMALIZATION = [False, True]
EPOCHS = 1000
EARLY_STOPPING_EPOCHS = 10
BATCH_SIZE = 64
LEARNING_RATE = 0.001
SEED = 42
mean_imageNet = [0.485, 0.456, 0.406]  # ImageNet Mean
std_imageNet = [0.229, 0.224, 0.225]  # ImageNet STD
device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
OUTPUT_DIR = './output/'

# Determinism
random.seed(SEED)
if torch.cuda.is_available():
    torch.backends.cudnn.deterministic = True
    torch.backends.cudnn.benchmark = False
    torch.cuda.manual_seed_all(SEED)

# Data Augmentations
augmented_transform = transforms.Compose([
    transforms.RandomResizedCrop(224, scale=(0.8, 1.0)),
    transforms.RandomHorizontalFlip(),
    transforms.RandomRotation(10),
    transforms.ColorJitter(brightness=0.2, contrast=0.2, saturation=0.2, hue=0.1),
    transforms.ToTensor(),
    transforms.Normalize(mean=mean_imageNet, std=std_imageNet)
])

validation_transform = transforms.Compose([
    transforms.Resize(256),  # Resize the shortest side to 256
    transforms.CenterCrop(224),
    transforms.ToTensor(),
    transforms.Normalize(mean=mean_imageNet, std=std_imageNet)
])

# Datasets and loaders
train_dataset = datasets.ImageFolder('./train/', transform=augmented_transform)
validation_dataset = datasets.ImageFolder('./validation/', transform=validation_transform)
train_loader = DataLoader(train_dataset, batch_size=BATCH_SIZE, shuffle=True)
validation_loader = DataLoader(validation_dataset, batch_size=BATCH_SIZE, shuffle=False)
class_names = train_dataset.classes


class TransferLearningModel(nn.Module):
    def __init__(self, base_model, num_classes, dropout_rate, use_bn=False):
        super(TransferLearningModel, self).__init__()
        self.base_model = base_model

        # Freeze the parameters of the pretrained model
        for param in self.base_model.parameters():
            param.requires_grad = False

        # Replacing the last fully connected layer with a custom classifier
        num_features = self.base_model.fc.in_features  # Pretrained model features
        self.base_model.fc = self._build_classifier(num_features, num_classes, dropout_rate, use_bn)

    @staticmethod
    def _build_classifier(in_features, num_classes, dropout_rate, use_bn):  # FC Layers
        layers = [nn.Dropout(dropout_rate)]  # DP Layer
        if use_bn:  # BN Layer
            layers.append(nn.BatchNorm1d(in_features))
        layers.append(nn.Linear(in_features, num_classes))  # Dense Layer
        return nn.Sequential(*layers)

    def forward(self, x):
        return self.base_model(x)


def train_one_epoch(model, loader, criterion, optimizer, scheduler):
    model.train()
    total_loss = 0.0
    all_labels = []
    all_predictions = []

    for images, labels in tqdm(loader, desc="Training"):
        images, labels = images.to(device), labels.to(device)

        optimizer.zero_grad()  # Reset
        outputs = model(images)
        loss = criterion(outputs, labels)
        loss.backward()
        optimizer.step()
        scheduler.step()

        total_loss += loss.item() * images.size(0)

        _, predictions = torch.max(outputs, 1)
        all_labels.extend(labels.cpu().numpy())
        all_predictions.extend(predictions.cpu().numpy())

    avg_loss = total_loss / len(loader.dataset)
    accuracy = accuracy_score(all_labels, all_predictions)
    precision, recall, f1, _ = precision_recall_fscore_support(all_labels, all_predictions, average='weighted',
                                                               zero_division=0)

    return avg_loss, accuracy, precision, recall, f1


def validate(model, loader, criterion):
    model.eval()
    total_loss = 0.0
    all_labels = []
    all_predictions = []

    with torch.no_grad():
        for images, labels in tqdm(loader, desc="Validation"):
            images, labels = images.to(device), labels.to(device)
            outputs = model(images)
            loss = criterion(outputs, labels)

            total_loss += loss.item() * images.size(0)

            _, predictions = torch.max(outputs, 1)
            all_labels.extend(labels.cpu().numpy())
            all_predictions.extend(predictions.cpu().numpy())

    avg_loss = total_loss / len(loader.dataset)
    accuracy = accuracy_score(all_labels, all_predictions)
    precision, recall, f1, _ = precision_recall_fscore_support(all_labels, all_predictions, average='weighted',
                                                               zero_division=0)

    return avg_loss, accuracy, precision, recall, f1, all_labels, all_predictions


def main(model_index):
    if not os.path.exists(OUTPUT_DIR):
        os.makedirs(OUTPUT_DIR)

    # Determinism
    torch.manual_seed(SEED)
    np.random.seed(SEED)

    early_stopping_counter = 0

    for dropout_rate in DROPOUT_RATES:
        for use_bn in BATCH_NORMALIZATION:
            print(f'[{model_index}] Model: Dropout Rate: {dropout_rate} & Batch Normalization: {use_bn}')
            model_index += 1
            base_model = models.resnet152(weights=models.ResNet152_Weights.IMAGENET1K_V2)  # Initialize Weights
            best_val_loss = float('inf')
            model_instance = TransferLearningModel(base_model=base_model, num_classes=len(class_names),
                                                   dropout_rate=dropout_rate, use_bn=use_bn).to(device)
            criterion = nn.CrossEntropyLoss()
            optimizer = optim.Adam(model_instance.parameters(), lr=LEARNING_RATE)
            scheduler = OneCycleLR(optimizer, max_lr=LEARNING_RATE, epochs=EPOCHS, steps_per_epoch=len(train_loader))

            model_filename = OUTPUT_DIR + f'sd_dp_{dropout_rate}_bn_{use_bn}.pth'
            cm_filename = OUTPUT_DIR + f'cm_dp_{dropout_rate}_bn_{use_bn}.png'
            excel_filename = OUTPUT_DIR + f'log_dp_{dropout_rate}_bn_{use_bn}.xlsx'

            # Create an empty dataframe to store logs
            logs_df = pd.DataFrame(columns=[
                "Epoch", "Duration (s)", "Train_Loss", "Train_Accuracy",
                "Train_Precision", "Train_Recall", "Train_F1",
                "Val_Loss", "Val_Accuracy", "Val_Precision", "Val_Recall", "Val_F1"
            ])

            for epoch in range(EPOCHS):
                start_time = time.time()

                train_loss, train_acc, train_precision, train_recall, train_f1 = train_one_epoch(model_instance,
                                                                                                 train_loader,
                                                                                                 criterion, optimizer,
                                                                                                 scheduler)

                val_loss, val_acc, val_precision, val_recall, val_f1, val_labels, val_predictions = validate(
                    model_instance, validation_loader, criterion)

                epoch_duration = time.time() - start_time

                # Appending results to the logs dataframe
                new_row = pd.DataFrame({
                    "Epoch": [epoch + 1],
                    "Duration (s)": [epoch_duration],
                    "Train_Loss": [train_loss],
                    "Train_Accuracy": [train_acc],
                    "Train_Precision": [train_precision],
                    "Train_Recall": [train_recall],
                    "Train_F1": [train_f1],
                    "Val_Loss": [val_loss],
                    "Val_Accuracy": [val_acc],
                    "Val_Precision": [val_precision],
                    "Val_Recall": [val_recall],
                    "Val_F1": [val_f1]
                })
                logs_df = pd.concat([logs_df, new_row], ignore_index=True)
                print(new_row)
                # Model checkpointing
                if val_loss < best_val_loss:
                    best_val_loss = val_loss
                    torch.save(model_instance.state_dict(), model_filename)
                    print(f'Model Saved at epoch: {epoch + 1}')
                    early_stopping_counter = 0

                    # Generate confusion matrix
                    cm = confusion_matrix(val_labels, val_predictions)
                    plt.figure(figsize=(10, 10))
                    plt.imshow(cm, cmap='Blues')
                    plt.title('Confusion Matrix')
                    plt.colorbar()
                    tick_marks = np.arange(len(class_names))
                    plt.xticks(tick_marks, class_names, rotation=45)
                    plt.yticks(tick_marks, class_names)
                    thresh = cm.max() / 2.
                    for i, j in itertools.product(range(cm.shape[0]), range(cm.shape[1])):
                        plt.text(j, i, cm[i, j],
                                 horizontalalignment="center",
                                 color="white" if cm[i, j] > thresh else "black")
                    plt.ylabel('True label')
                    plt.xlabel('Predicted label')
                    plt.tight_layout()
                    plt.savefig(cm_filename, dpi=600)
                    plt.close()

                else:
                    early_stopping_counter += 1

                if early_stopping_counter >= EARLY_STOPPING_EPOCHS:
                    print("Early stopping activated!")
                    break

            # Save the dataframe to an Excel file
            logs_df.to_excel(excel_filename, index=False, engine='openpyxl')
            torch.cuda.empty_cache()


if __name__ == '__main__':
    main(1)  # Index 1
    print(f'Successfully completed.')
