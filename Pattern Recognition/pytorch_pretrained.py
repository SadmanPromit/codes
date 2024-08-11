import torch
import torchvision.models as models

model = models.vgg16(weights='IMAGENET1K_V1')
torch.save(model.state_dict(), 'vgg16-my-training.pth')
model = models.vgg16()
model.load_state_dict(torch.load('vgg16-my-training.pth'))
print(model)
