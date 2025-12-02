import torch
omega = torch.tensor([1, 2, 3, 4, 5, 6])
pos = torch.randint(0, 10, (2, 3, 4))
freq = torch.einsum("..., f -> ... f", pos, omega)
print(pos)
print(freq)
print(freq.shape)