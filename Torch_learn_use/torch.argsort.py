import torch

a = [torch.randint(10, 20, (2, 4)), torch.randint(0, 10, (2, 4))]
print(a)
a = torch.cat(a, dim=0)
print(a)
argsort = torch.argsort(a, dim=1)
print(argsort)
print([a[i, row] for i, row in enumerate(argsort)])
a = torch.stack([a[i, row] for i, row in enumerate(argsort)], dim=0)
print(a)