import torch
import numpy as np

data = [[1, 2], [3, 4]]
x_data = torch.tensor(data)
print(x_data)
np_array = np.array(data)
print(np_array)
x_np = torch.from_numpy(np_array)
print(type(np_array))
x_ones = torch.ones_like(x_data)
x_rand = torch.rand_like(x_data, dtype=torch.float)
print(x_rand)
shape = (3, 5)
rand_tensor = torch.rand(shape)
ones_tensor = torch.ones(shape)
zeros_tensor = torch.zeros(shape)
tensor = torch.rand(5, 7)
print(tensor.device)
device = 'cpu'
if torch.cuda.is_available():
    device = 'cuda'
print(tensor.device)
tensor = torch.rand(5, 7)
print(tensor.device)
tensor = tensor.to(device)
print(tensor.device)
print(tensor)
print(tensor[:, 0])
print(tensor[:, -1])
t1 = torch.cat([tensor, tensor], dim=1)
print(t1)
print(t1.shape)
y1 = tensor @ tensor.T
print(y1.shape)
y1 = tensor.matmul(tensor.T)
torch.matmul(tensor, tensor.T, out=y1)
z1 = tensor * tensor
z2 = tensor.mul(tensor)
z3 = torch.mul(tensor, tensor)
agg = tensor.sum()
agg_item = agg.item()
print(agg)
tensor.add_(1)
print(tensor)
tensor = tensor.to('cpu')
n = tensor.numpy()
tensor.add_(5)
print(tensor)
print(n)
n = np.ones(5)
print(n)
t = torch.from_numpy(n)
print(t)