import torch
from torch import nn
from torch.utils.data import DataLoader
from torchvision import datasets
from torchvision.transforms import ToTensor
import matplotlib.pyplot as plt

# Load the Dataset
training_data = datasets.FashionMNIST(root='./data', train=True, download=True, transform=ToTensor())
test_data = datasets.FashionMNIST(root='./data', train=False, download=True, transform=ToTensor())
cifar_tdata = datasets.CIFAR10(root='./data', train=True, download=True, transform=ToTensor())
plt.imshow(training_data[2][0].reshape(28, 28))
plt.show()
train_dataloader = DataLoader(training_data, batch_size=64)
test_dataloader = DataLoader(test_data, batch_size=64)
for X, y in test_dataloader:
    print(X.shape)
    print(y.dtype)
    break

# Select GPU device
device = 'cuda'


# Defining the Model
class NeuralNetwork(nn.Module):
    def __init__(self):
        super().__init__()
        self.flatten = nn.Flatten()
        self.linear_relu_stack = nn.Sequential(
            nn.Linear(28 * 28, 512),
            nn.ReLU(),
            nn.Linear(512, 512),
            nn.ReLU(),
            nn.Linear(512, 10)
        )

    def forward(self, x):
        x = self.flatten(x)
        prob = self.linear_relu_stack(x)
        return prob


# Defining Loss Function and Optimizer
model = NeuralNetwork().to(device)
print(model)
model.state_dict()
for k in model.state_dict():
    print(k)
for p in model.parameters():
    print(p)
loss_fn = nn.CrossEntropyLoss()
optimizer = torch.optim.SGD(model.parameters(), lr=1e-3)


# Training a Model
def train(dataloader, model, loss_fn, optimizer):
    size = len(dataloader.dataset)
    model.train()
    for batch, (X, y) in enumerate(dataloader):
        X, y = X.to(device), y.to(device)

        # forward pass
        pred = model(X)  # y-hat
        loss = loss_fn(pred, y)  # Difference between y-hat and y

        # backprop
        loss.backward()  # Calculate the gradients
        optimizer.step()  # Update gradients
        optimizer.zero_grad()  # Clear everything for the next iteration


# Testing a Model
def test(dataloader, model, loss_fn):
    size = len(dataloader.dataset)
    num_batches = len(dataloader)
    model.eval()
    test_loss, correct = 0, 0
    with torch.no_grad():
        for X, y in dataloader:
            X, y = X.to(device), y.to(device)
            pred = model(X)
            test_loss = test_loss + loss_fn(pred, y)
            correct = correct + (pred.argmax(1) == y).type(torch.float).sum().item()
    test_loss /= num_batches
    correct /= size
    print(f"Test Error: \n Accuracy: {(100 * correct): > 0.1f}%, Avg loss: {test_loss: > 0f}\n")


# Running epochs
epochs = 2
for n in range(epochs):
    print(f"Epoch {(n + 1)}\n")
    train(train_dataloader, model, loss_fn, optimizer)
    test(train_dataloader, model, loss_fn)

# Saving Models
torch.save(model.state_dict(), "model.pth")
print("Model saved")

# Loading Models
model = NeuralNetwork().to(device)
model.load_state_dict(torch.load("model.pth"))

# Fine-tune saved Models
loss_fn = nn.CrossEntropyLoss()
optimizer = torch.optim.SGD(model.parameters(), lr=1e-3)
epochs = 5
for n in range(epochs):
    print(f"Epoch {(n + 1)}\n")
    train(train_dataloader, model, loss_fn, optimizer)
    test(train_dataloader, model, loss_fn)
