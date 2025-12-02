import torch

mask = torch.arange(int(2 * 4 * 4))
print(mask)

mask = torch.randint(0, 10, size=(2, 3, 4))
print(mask)
print(mask // 2)