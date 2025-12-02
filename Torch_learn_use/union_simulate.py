import torch

"""
实现一个并集
"""

a = torch.ones((2, 4, 4), dtype=torch.int32)
a[0:1, 1:3, 1:3] = 0
# print(a)
b = torch.ones((2, 4, 4), dtype=torch.int32)
b[1:2, 0:2, 1:3] = 0
# print(b)

# a 与 b 并集
c = a * b
# print(c)

mask_e = c.flatten()  # (T*H*W,)
print(mask_e)
mask_p = torch.argwhere(mask_e == 0).squeeze()
mask_e = torch.nonzero(mask_e).squeeze()
print(mask_p)
print(mask_e)




