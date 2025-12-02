import torch
x = torch.randint(1, 4, (1, 1, 2, 3))
y = torch.randint(1, 3, (3, 2, 2, 3))
z = y * x
# print(x)
# print(y)
# print(z)
print(z.shape)
