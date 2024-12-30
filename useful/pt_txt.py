# pt_txt: v1 © 2024 Sadman Sakib Khan Promit
import torch

file = 'G:/My Drive/codes/Senior Design Project II/Disease Classification/webapp/model.pth'
model = torch.load(file, weights_only = False)

try:
    with open("pt.txt", "a") as file:
        file.write(f"{model}")
except Exception as e:
    pass