import torch
import torch.nn as nn
import torchvision.models as models


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


# Custom SELayer definition
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


# Custom SEResNetBlock definition
class SEResNetBlock(nn.Module):
    expansion = 4

    def __init__(self, in_planes, planes, stride=1, reduction=16):
        super(SEResNetBlock, self).__init__()
        self.conv1 = nn.Conv2d(in_planes, planes, kernel_size=1, bias=False)
        self.bn1 = nn.BatchNorm2d(planes)
        self.conv2 = nn.Conv2d(planes, planes, kernel_size=3, stride=stride, padding=1, bias=False)
        self.bn2 = nn.BatchNorm2d(planes)
        self.conv3 = nn.Conv2d(planes, self.expansion * planes, kernel_size=1, bias=False)
        self.bn3 = nn.BatchNorm2d(self.expansion * planes)

        self.se = SELayer(self.expansion * planes, reduction)

        self.shortcut = nn.Sequential()
        if stride != 1 or in_planes != self.expansion * planes:
            self.shortcut = nn.Sequential(
                nn.Conv2d(in_planes, self.expansion * planes, kernel_size=1, stride=stride, bias=False),
                nn.BatchNorm2d(self.expansion * planes)
            )

    def forward(self, x):
        out = nn.ReLU()(self.bn1(self.conv1(x)))
        out = nn.ReLU()(self.bn2(self.conv2(out)))
        out = self.bn3(self.conv3(out))
        out = self.se(out)
        out += self.shortcut(x)
        out = nn.ReLU()(out)
        return out


# Custom SEResNet model definition
class SEResNet(nn.Module):
    def __init__(self, block, num_blocks, num_classes=1000):
        super(SEResNet, self).__init__()
        self.in_planes = 64

        self.conv1 = nn.Conv2d(3, 64, kernel_size=3, stride=1, padding=1, bias=False)
        self.bn1 = nn.BatchNorm2d(64)
        self.layer1 = self._make_layer(block, 64, num_blocks[0], stride=1)
        self.layer2 = self._make_layer(block, 128, num_blocks[1], stride=2)
        self.layer3 = self._make_layer(block, 256, num_blocks[2], stride=2)
        self.layer4 = self._make_layer(block, 512, num_blocks[3], stride=2)
        self.linear = nn.Linear(512 * block.expansion, num_classes)

    def _make_layer(self, block, planes, num_blocks, stride):
        strides = [stride] + [1] * (num_blocks - 1)
        layers = []
        for stride in strides:
            layers.append(block(self.in_planes, planes, stride))
            self.in_planes = planes * block.expansion
        return nn.Sequential(*layers)

    def forward(self, x):
        out = nn.ReLU()(self.bn1(self.conv1(x)))
        out = self.layer1(out)
        out = self.layer2(out)
        out = self.layer3(out)
        out = self.layer4(out)
        out = nn.AdaptiveAvgPool2d((1, 1))(out)
        out = out.view(out.size(0), -1)
        out = self.linear(out)
        return out


# Function to count parameters
def count_parameters(model):
    return sum(p.numel() for p in model.parameters())


# Function to estimate FLOPs
def get_flops(model, input_dim):
    model.eval()
    device = next(model.parameters()).device  # Get the device of the model
    flops = torch.tensor([0.0], device=device)

    def add_hooks(module):
        if len(list(module.children())) > 0:
            return
        module.register_forward_hook(hook)

    def hook(module, input0, output):
        input0 = input0[0]
        output = output[0]

        batch_size = input0.shape[0]
        output_elements = output.numel()
        input_elements = input0.numel()

        flops_per_element = 2  # Assuming multiply-add operations
        if isinstance(module, (nn.Conv2d, nn.Linear)):
            flops_per_element = input_elements // batch_size

        flops.add_(batch_size * output_elements * flops_per_element)

    model.apply(add_hooks)

    dummy_input = torch.randn(input_dim)
    model(dummy_input.to(device))

    return int(flops.item())


# Models
pre_trained_model = models.resnet152(weights=models.ResNet152_Weights.IMAGENET1K_V2)
transfer_learning_model = TransferLearningModel(pre_trained_model, num_classes=20, dropout_rate=0.5, use_bn=True)
se_net = SEResNet(SEResNetBlock, [3, 8, 36, 3], num_classes=20)

# Count parameters
total_params_resnet152 = count_parameters(transfer_learning_model)
total_params_se_net = count_parameters(se_net)

# Estimate FLOPs
input_size = (1, 3, 224, 224)  # BATCH_SIZE of 1
flops_resnet152 = get_flops(transfer_learning_model, input_size)
flops_se_net = get_flops(se_net, input_size)

print(f"ResNet - Total Parameters: {total_params_resnet152}, Estimated Computations: {flops_resnet152}")
print(f"SeNet - Total Parameters: {total_params_se_net}, Estimated Computations: {flops_se_net}")
