# behavior_analysis.py
import os
from pathlib import Path
import torch
import torch.nn as nn
import torchvision.models as models
from torch.utils.data import DataLoader, Dataset, random_split
from torchvision import transforms
from torchvision.models import ResNet152_Weights
from tqdm import tqdm
import time
from torch.optim import Adam
from torch.optim.lr_scheduler import ReduceLROnPlateau
import logging
from torch.cuda.amp import GradScaler, autocast
import av
import yaml
import torch.utils.checkpoint as checkpoint
from sklearn.metrics import confusion_matrix, accuracy_score, precision_score, recall_score, f1_score
import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np


class Config:
    def __init__(self, config_file='config.yaml'):
        with open(config_file) as file:
            self.config_data = yaml.load(file, Loader=yaml.FullLoader)

    def __getitem__(self, key):
        return self.config_data[key]


# Create a config object
config = Config()

# Use the config object to set hyperparameters and paths
num_epochs = config['num_epochs']
dataset_path = Path(config['dataset_path'])
checkpoint_path = Path(config['checkpoint_path'])
learning_rate = config['learning_rate']
batch_size = config['batch_size']
num_classes = config['num_classes']
class_names = config['class_names']
num_frames = config['num_frames']
accumulation_steps = config['accumulation_steps']

# Set up logging
logger = logging.getLogger(__name__)
logger.setLevel(logging.INFO)
c_handler = logging.StreamHandler()
f_handler = logging.FileHandler('model_training.log')
c_handler.setLevel(logging.INFO)
f_handler.setLevel(logging.INFO)
c_format = logging.Formatter('%(name)s - %(levelname)s - %(message)s')
f_format = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
c_handler.setFormatter(c_format)
f_handler.setFormatter(f_format)
if not logger.handlers:
    logger.addHandler(c_handler)
    logger.addHandler(f_handler)


class CrowdBehaviorModel(nn.Module):
    def __init__(self, num_classes):
        super(CrowdBehaviorModel, self).__init__()
        base_model = models.resnet152(weights=ResNet152_Weights.DEFAULT)  # Use pre-trained weights

        # Enable gradient computation for all parameters in the base model
        for param in base_model.parameters():
            param.requires_grad = True

        self.conv = nn.Sequential(*list(base_model.children())[:-1])
        self.lstm = nn.LSTM(input_size=2048, hidden_size=512, num_layers=2, batch_first=True, dropout=0.5)
        self.fc = nn.Linear(512, num_classes)
        self.dropout = nn.Dropout(0.5)  # Define dropout layer

        # Dummy parameter for gradient checkpointing
        self.dummy_param = nn.Parameter(torch.empty(0), requires_grad=True)

    def forward(self, x):
        batch_size, timesteps, C, H, W = x.size()
        cnn_out = checkpoint.checkpoint(self.conv, x.view(batch_size * timesteps, C, H, W)).squeeze(-1).squeeze(-1)
        rnn_in = cnn_out.view(batch_size, timesteps, -1)
        rnn_out, _ = self.lstm(rnn_in)
        x = self.dropout(rnn_out[:, -1, :])
        x = self.fc(x)
        return x


class VideoDataset(Dataset):
    def __init__(self, root_dir, class_labels, transform_func=None, num_frames=16):
        self.root_dir = root_dir
        self.transform = transform_func
        self.num_frames = num_frames
        self.classes = class_labels
        self.video_paths = []
        self.video_labels = []

        for label, class_name in enumerate(self.classes):
            class_path = os.path.join(self.root_dir, class_name)
            for video_name in os.listdir(class_path):
                self.video_paths.append(os.path.join(class_path, video_name))
                self.video_labels.append(label)

    def load_video(self, path):
        frames = []
        frame_rate = None  # Initialize frame_rate here
        try:
            container = av.open(path)
            video_stream = next(s for s in container.streams if s.type == 'video')
            for frame in container.decode(video_stream):
                img = frame.to_image()  # PIL Image
                if self.transform:
                    img = self.transform(img)  # transform PIL Image to tensor
                frames.append(img)
            frame_rate = video_stream.average_rate
        except av.AVError as ave:
            logger.error(f"Failed to open and decode video file at {path} due to AVError: {ave}")
        except Exception as e:
            logger.error(f"Failed to process video file at {path} due to an unexpected error: {e}")
        return frames, frame_rate

    def __len__(self):
        return len(self.video_paths)

    def __getitem__(self, idx):
        frames, frame_rate = self.load_video(self.video_paths[idx])
        if len(frames) < num_frames:
            frames += [frames[-1]] * (num_frames - len(frames))  # repeat the last frame
        elif len(frames) > num_frames:
            skip = len(frames) // num_frames
            frames = [frames[i] for i in range(0, len(frames), skip)][:num_frames]
        label = torch.tensor(self.video_labels[idx])  # Convert label to tensor
        return torch.stack(frames), label


# Create model and move it to GPU
model = CrowdBehaviorModel(num_classes=len(class_names))
device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
model = model.to(device)

# Load model if there's a pretrained model
start_epoch = 0
if checkpoint_path.is_file():
    try:
        checkpoint = torch.load(checkpoint_path)
        model.load_state_dict(checkpoint['model_state_dict'])

        # Ensure requires_grad=True for all parameters
        for param in model.parameters():
            param.requires_grad = True

        start_epoch = checkpoint['epoch']
        logger.info("Loaded pre-trained model")
    except Exception as e:
        logger.error("Failed to load pre-trained model due to {}".format(e))
else:
    logger.info("No pre-trained model found")

transform = transforms.Compose(
    [transforms.Resize((224, 224), transforms.InterpolationMode.BICUBIC),
     transforms.ToTensor(),
     transforms.Normalize(mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225])])

dataset = VideoDataset(root_dir=dataset_path, class_labels=class_names, transform_func=transform, num_frames=num_frames)

# Split the dataset
total_size = len(dataset)
train_size = int(0.7 * total_size)
val_size = int(0.15 * total_size)
test_size = total_size - train_size - val_size
train_dataset, val_dataset, test_dataset = random_split(dataset, [train_size, val_size, test_size])

# DataLoader for test dataset
train_loader = DataLoader(dataset=train_dataset, batch_size=batch_size, shuffle=True)
val_loader = DataLoader(dataset=val_dataset, batch_size=batch_size, shuffle=False)
test_loader = DataLoader(dataset=test_dataset, batch_size=batch_size, shuffle=False)

# Define the optimizer, the loss function and the learning rate scheduler
optimizer = Adam(model.parameters(), lr=learning_rate)
if checkpoint_path.is_file():
    try:
        checkpoint = torch.load(checkpoint_path)
        optimizer.load_state_dict(checkpoint['optimizer_state_dict'])
        logger.info("Loaded optimizer state")
    except Exception as e:
        logger.error("Failed to load optimizer state due to {}".format(e))

criterion = nn.CrossEntropyLoss()
scheduler = ReduceLROnPlateau(optimizer, mode='min', factor=0.1, patience=10, verbose=True)

# Initialize GradScaler for mixed precision training
scaler = GradScaler()

# Initialize lists to save training and validation losses and accuracies
train_losses = []
train_accuracies = []
val_losses = []
val_accuracies = []
best_val_acc = 0  # initialize the best validation accuracy


def calculate_accuracy(predictions, y):
    top_pred = predictions.argmax(1)
    correct = top_pred.eq(y).sum().item()
    acc = correct / len(y)
    return acc


def train_one_epoch(model, iterator, criterion, optimizer, device, scaler):
    model.train()

    epoch_loss = 0
    epoch_acc = 0

    optimizer.zero_grad()  # Reset gradients tensors

    for i, (x, y) in enumerate(tqdm(iterator)):
        x = x.to(device)
        y = y.to(device)

        with autocast():
            predictions = model(x)
            loss = criterion(predictions, y)

        scaler.scale(loss).backward()  # Backward pass (backpropagation)

        if (i + 1) % accumulation_steps == 0:  # Wait for several backward steps
            scaler.step(optimizer)  # Now we can do an optimizer step
            scaler.update()
            optimizer.zero_grad()  # Reset gradients tensors

        acc = calculate_accuracy(predictions, y)
        epoch_loss += loss.item()
        epoch_acc += acc

    torch.cuda.empty_cache()
    return epoch_loss / len(iterator), epoch_acc / len(iterator)


def validate_one_epoch(model, iterator, criterion, device):
    model.eval()

    epoch_loss = 0
    epoch_acc = 0

    with torch.no_grad():
        for (x, y) in tqdm(iterator):
            x = x.to(device)
            y = y.to(device)

            predictions = model(x)
            loss = criterion(predictions, y)

            acc = calculate_accuracy(predictions, y)
            epoch_loss += loss.item()
            epoch_acc += acc

    torch.cuda.empty_cache()
    return epoch_loss / len(iterator), epoch_acc / len(iterator)


# Testing phase
def test_one_epoch(model, iterator, device):
    model.eval()
    y_true = []
    y_pred = []

    with torch.no_grad():
        for (x, y) in iterator:
            x = x.to(device)
            y = y.to(device)

            predictions = model(x)
            _, predicted = torch.max(predictions.data, 1)

            y_true.extend(y.cpu().numpy())
            y_pred.extend(predicted.cpu().numpy())

    return np.array(y_true), np.array(y_pred)


# Training loop
early_stop_after = 10  # Number of epochs to wait for improvement in validation loss
no_improve_epoch = 0
best_val_loss = float('inf')  # initialize the best validation loss

for epoch in range(start_epoch, num_epochs):
    start_time = time.time()

    train_loss, train_acc = train_one_epoch(model, train_loader, criterion, optimizer, device, scaler)
    val_loss, val_acc = validate_one_epoch(model, val_loader, criterion, device)

    train_losses.append(train_loss)
    train_accuracies.append(train_acc)
    val_losses.append(val_loss)
    val_accuracies.append(val_acc)

    scheduler.step(val_loss)

    # Save model checkpoint if validation loss has improved
    if val_loss < best_val_loss:
        best_val_loss = val_loss
        no_improve_epoch = 0
        torch.save({
            'epoch': epoch,
            'model_state_dict': model.state_dict(),
            'optimizer_state_dict': optimizer.state_dict(),
            'train_losses': train_losses,
            'val_losses': val_losses,
            'train_accuracies': train_accuracies,
            'val_accuracies': val_accuracies
        }, checkpoint_path)
        logger.info(f"Saved model checkpoint to '{checkpoint_path}'")
    else:
        no_improve_epoch += 1
        if no_improve_epoch == early_stop_after:
            logger.info("No improvement in validation loss for {} epochs. Stopping training.".format(early_stop_after))
            break

    end_time = time.time()
    epoch_mins, epoch_secs = divmod(end_time - start_time, 60)
    logger.info(f"Epoch: {epoch + 1:02} | Time: {epoch_mins:.0f}m {epoch_secs:.0f}s")
    logger.info(f"\tTrain Loss: {train_loss:.3f} | Train Acc: {train_acc * 100:.2f}%")
    logger.info(f"\t Val. Loss: {val_loss:.3f} |  Val. Acc: {val_acc * 100:.2f}%")


y_true, y_pred = test_one_epoch(model, test_loader, device)

# Compute metrics
accuracy = accuracy_score(y_true, y_pred)
precision = precision_score(y_true, y_pred, average='weighted')
recall = recall_score(y_true, y_pred, average='weighted')

# Generate confusion matrix
cm = confusion_matrix(y_true, y_pred)

# Save metrics
with open('metrics.txt', 'w') as f:
    f.write(f"Accuracy: {accuracy}\n")
    f.write(f"Precision: {precision}\n")
    f.write(f"Recall: {recall}\n")

# Plot confusion matrix
plt.figure(figsize=(10,7))
sns.heatmap(cm, annot=True, fmt='d')
plt.xlabel('Predicted')
plt.ylabel('Truth')
plt.savefig('confusion_matrix.png')