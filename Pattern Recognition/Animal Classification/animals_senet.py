import torch
import torch.nn as nn
import torchvision.transforms as transforms
import torchvision.datasets as datasets
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


def conv1x1(in_planes, out_planes, stride=1):
    """1x1 convolution with no padding"""
    return nn.Conv2d(in_planes, out_planes, kernel_size=1, stride=stride, bias=False)


class SELayer(nn.Module):
    def __init__(self, channel, reduction=16):
        super(SELayer, self).__init__()
        self.avg_pool = nn.AdaptiveAvgPool2d(1)
        self.fc = nn.Sequential(
            nn.Linear(channel, channel // reduction, bias=False),
            nn.ReLU(inplace=True),
            nn.Linear(channel // reduction, channel, bias=False),
            nn.Sigmoid()
        )

    def forward(self, x):
        b, c, _, _ = x.size()
        y = self.avg_pool(x).view(b, c)
        y = self.fc(y).view(b, c, 1, 1)
        return x * y.expand_as(x)


class SEResNetBlock(nn.Module):
    expansion = 4

    def __init__(self, in_planes, planes, stride=1, down_sample=None, groups=1,
                 base_width=64, dilation=1, norm_layer=None, reduction=16, use_bn=True):
        super(SEResNetBlock, self).__init__()
        if norm_layer is None and use_bn:
            norm_layer = nn.BatchNorm2d
        width = int(planes * (base_width / 64.)) * groups
        # Both self.conv2 and self.down_sample layers down_sample the input when stride != 1
        self.conv1 = nn.Conv2d(in_planes, width, kernel_size=1, bias=False)
        self.bn1 = norm_layer(width)
        self.conv2 = nn.Conv2d(width, width, kernel_size=3, stride=stride,
                               padding=dilation, groups=groups, bias=False, dilation=dilation)
        self.bn2 = norm_layer(width)
        self.conv3 = nn.Conv2d(width, planes * self.expansion, kernel_size=1, bias=False)
        self.bn3 = norm_layer(planes * self.expansion)
        self.relu = nn.ReLU(inplace=True)
        self.se = SELayer(planes * self.expansion, reduction)
        self.down_sample = down_sample
        self.stride = stride

    def forward(self, x):
        residual = x

        out = self.conv1(x)
        out = self.bn1(out)
        out = self.relu(out)

        out = self.conv2(out)
        out = self.bn2(out)
        out = self.relu(out)

        out = self.conv3(out)
        out = self.bn3(out)

        out = self.se(out)

        if self.down_sample is not None:
            residual = self.down_sample(x)

        out += residual
        out = self.relu(out)

        return out


class SEResNet(nn.Module):
    def __init__(self, block, layers, num_classes, dropout_rate, use_bn=True, zero_init_residual=False,
                 groups=1, width_per_group=64, replace_stride_with_dilation=None,
                 norm_layer=None):
        super(SEResNet, self).__init__()
        if norm_layer is None:
            norm_layer = nn.BatchNorm2d
        self._norm_layer = norm_layer

        self.in_planes = 64
        self.dilation = 1
        if replace_stride_with_dilation is None:
            # each element in the tuple indicates if we should replace
            # the 2x2 stride with a dilated convolution instead
            replace_stride_with_dilation = [False, False, False]
        if len(replace_stride_with_dilation) != 3:
            raise ValueError("replace_stride_with_dilation should be None "
                             "or a 3-element tuple, got {}".format(replace_stride_with_dilation))
        self.groups = groups
        self.base_width = width_per_group
        self.conv1 = nn.Conv2d(3, self.in_planes, kernel_size=7, stride=2, padding=3,
                               bias=False)
        self.bn1 = norm_layer(self.in_planes)
        self.relu = nn.ReLU(inplace=True)
        self.max_pool = nn.MaxPool2d(kernel_size=3, stride=2, padding=1)
        self.layer1 = self._make_layer(block, 64, layers[0], use_bn=use_bn)
        self.layer2 = self._make_layer(block, 128, layers[1], stride=2, use_bn=use_bn,
                                       dilate=replace_stride_with_dilation[0])
        self.layer3 = self._make_layer(block, 256, layers[2], stride=2,
                                       dilate=replace_stride_with_dilation[1])
        self.layer4 = self._make_layer(block, 512, layers[3], stride=2,
                                       dilate=replace_stride_with_dilation[2])
        self.avg_pool = nn.AdaptiveAvgPool2d((1, 1))
        self.dropout = nn.Dropout(dropout_rate)
        self.fc = nn.Linear(512 * block.expansion, num_classes)

        for m in self.modules():
            if isinstance(m, nn.Conv2d):
                nn.init.kaiming_normal_(m.weight, mode='fan_out', nonlinearity='relu')
            elif isinstance(m, (nn.BatchNorm2d, nn.GroupNorm)):
                nn.init.constant_(m.weight, 1)
                nn.init.constant_(m.bias, 0)

        # Zero-initialize the last BN in each residual branch,
        # so that the residual branch starts with zeros, and each residual block behaves like an identity.
        # This improves the model by 0.2~0.3% according to https://arxiv.org/abs/1706.02677
        if zero_init_residual:
            for m in self.modules():
                if isinstance(m, SEResNetBlock):
                    nn.init.constant_(m.bn3.weight, 0)

    def _make_layer(self, block, planes, blocks, stride=1, dilate=False, use_bn=True):
        norm_layer = self._norm_layer if use_bn else lambda num_features: nn.Identity()
        down_sample = None
        previous_dilation = self.dilation
        if dilate:
            self.dilation *= stride
            stride = 1
        if stride != 1 or self.in_planes != planes * block.expansion:
            down_sample = nn.Sequential(
                conv1x1(self.in_planes, planes * block.expansion, stride),
                norm_layer(planes * block.expansion),
            )

        layers = [block(self.in_planes, planes, stride, down_sample, self.groups,
                        self.base_width, previous_dilation, norm_layer, use_bn=use_bn)]
        self.in_planes = planes * block.expansion
        for _ in range(1, blocks):
            layers.append(block(self.in_planes, planes, groups=self.groups,
                                base_width=self.base_width, dilation=self.dilation,
                                norm_layer=norm_layer))

        return nn.Sequential(*layers)

    def forward(self, x):
        x = self.conv1(x)
        x = self.bn1(x)
        x = self.relu(x)
        x = self.max_pool(x)

        x = self.layer1(x)
        x = self.layer2(x)
        x = self.layer3(x)
        x = self.layer4(x)

        x = self.avg_pool(x)
        x = torch.flatten(x, 1)
        x = self.dropout(x)
        x = self.fc(x)

        return x


# ResNet configurations
def se_resnet152(num_classes, dropout_rate, use_bn):
    return SEResNet(SEResNetBlock, [3, 8, 36, 3], num_classes=num_classes, dropout_rate=dropout_rate, use_bn=use_bn)


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
            best_val_loss = float('inf')
            model_instance = (se_resnet152(num_classes=len(class_names), dropout_rate=dropout_rate, use_bn=use_bn).
                              to(device))
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
