import torch
import torch.nn as nn
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.metrics import roc_curve, auc
from sklearn.preprocessing import label_binarize
from torch.utils.data import Dataset, DataLoader
from itertools import cycle

# Hyperparameters
DROPOUT_RATE = 0.1

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
        self.conv1x1 = nn.Conv1d(32, 64, kernel_size=1)
        self.conv2 = nn.Conv1d(32, 64, kernel_size=3, stride=1, padding=1)
        self.dropout = nn.Dropout(dropout_prob)
        self.fc1 = nn.Linear(64 * 13, 128)
        self.fc2 = nn.Linear(128, 4)

    def forward(self, x):
        out_conv1 = nn.LeakyReLU()(self.conv1(x))
        out_conv1_matched = self.conv1x1(out_conv1)
        out_conv2 = nn.LeakyReLU()(self.conv2(out_conv1) + out_conv1_matched)
        out_conv2_flat = out_conv2.view(out_conv2.size(0), -1)
        out_fc1 = self.dropout(nn.LeakyReLU()(self.fc1(out_conv2_flat)))
        out_fc2 = self.fc2(out_fc1)
        return out_fc2

def load_saved_model(model_path):
    model = CNN().cuda()
    model.load_state_dict(torch.load(model_path))
    return model

def plot_roc_curve(model, data_loader):
    model.eval()
    true_labels = []
    predictions = []

    with torch.no_grad():
        for data, labels in data_loader:
            data = data.float().cuda()
            labels = labels.long().cuda()
            outputs = model(data)
            true_labels.extend(labels.cpu().numpy())
            predictions.extend(outputs.cpu().numpy())

    # Convert predictions list to a numpy array
    predictions = np.array(predictions)

    n_classes = 4
    true_labels_bin = label_binarize(true_labels, classes=range(n_classes))
    fpr, tpr, roc_auc = {}, {}, {}
    for i in range(n_classes):
        fpr[i], tpr[i], _ = roc_curve(true_labels_bin[:, i], predictions[:, i])
        roc_auc[i] = auc(fpr[i], tpr[i])

    fpr["micro"], tpr["micro"], _ = roc_curve(true_labels_bin.ravel(), predictions.ravel())
    roc_auc["micro"] = auc(fpr["micro"], tpr["micro"])

    plt.figure()
    lw = 2
    plt.plot(fpr["micro"], tpr["micro"], label='micro-average ROC curve (area = {0:0.2f})'.format(roc_auc["micro"]), color='deeppink', linestyle=':', linewidth=4)
    colors = cycle(['aqua', 'darkorange', 'cornflowerblue', 'green'])
    for i, color in zip(range(n_classes), colors):
        plt.plot(fpr[i], tpr[i], color=color, lw=lw, label='ROC curve of class {0} (area = {1:0.2f})'.format(i, roc_auc[i]))
    plt.plot([0, 1], [0, 1], 'k--', lw=lw)
    plt.xlim([0.0, 1.0])
    plt.ylim([0.0, 1.05])
    plt.xlabel('False Positive Rate')
    plt.ylabel('True Positive Rate')
    plt.title('Receiver Operating Characteristic to Multi-class')
    plt.legend(loc="lower right")
    plt.savefig('./roc_curve.png', dpi=600)
    plt.show()
    return './roc_curve.png'


if __name__ == "__main__":
    # Load validation data (modify this to match your validation dataset)
    val_data = pd.read_csv('thalBD_val.csv')
    val_dataset = ThalassemiaDataset(val_data)
    val_loader = DataLoader(val_dataset, batch_size=64, shuffle=False)

    # Load the saved model (modify this to match the path to your model)
    model_path = 'model.pth'
    model = load_saved_model(model_path)

    # Plot ROC curve
    roc_curve_image_path = plot_roc_curve(model, val_loader)
    print(f"The ROC curve has been saved to: {roc_curve_image_path}")
