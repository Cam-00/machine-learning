import torch
x = torch.tensor([[1, 2, 3], [4, 5, 6]])
x_unbind = x.unbind(dim=-1)
print(x_unbind)  # (tensor([1, 4]), tensor([2, 5]), tensor([3, 6]))

y = torch.randn(10, 8, 4, 4, 2)
print(y.shape)  # [10, 8, 4, 4, 2]
y1_unbind, y2_unbind = y.unbind(dim=-1)
print(y1_unbind.shape)  # [10, 8, 4, 4]
print(y2_unbind.shape)  # [10, 8, 4, 4]
