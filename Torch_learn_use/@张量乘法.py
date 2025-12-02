import torch

a = torch.randn(3, 4, 2, 12)
b = torch.randn(3, 4, 2, 12)
c = a @ b.transpose(-2, -1)
print(c.shape)  # [3, 4, 2, 2]