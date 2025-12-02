import torch
x = [torch.randint(0, 10, [2, 2, 3]), torch.randint(11, 20, [2, 2, 3])]
print(x)
print(torch.cat(x, dim=0))