import torch

x = torch.randint(0, 9, (2, 8, 3))
print(x)
x = x.view(2, -1, 2*2, 3)
print(x)
print(x.size())