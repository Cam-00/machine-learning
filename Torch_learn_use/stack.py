import torch

a = torch.tensor([[1, 2, 1], [2, 3, 4]])
b = torch.tensor([[5, 6, 7], [8, 9, 0]])
a_b = torch.stack((-a, b), dim=-1)
print(a_b)
print(a_b.shape)  # torch.Size([2, 3, 2])
"""
tensor([[[-1,  5],
         [-2,  6],
         [-1,  7]],

        [[-2,  8],
         [-3,  9],
         [-4,  0]]])
torch.Size([2, 3, 2])
"""

y = torch.randn(10, 8, 4, 4, 2)
print(y.shape)  # [10, 8, 4, 4, 2]
y1_unbind, y2_unbind = y.unbind(dim=-1)
print(y1_unbind.shape)  # [10, 8, 4, 4]
print(y2_unbind.shape)  # [10, 8, 4, 4]
y = torch.stack((-y2_unbind, y1_unbind), dim=-1)
print(y.shape)  # [10, 8, 4, 4, 2]