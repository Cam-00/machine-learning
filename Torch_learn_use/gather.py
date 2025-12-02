import torch

x = torch.randn(2, 4, 3)
mask_keep = torch.tensor([[[0, 0, 0], [1, 1, 1]], [[1, 1, 1],[2, 2, 2]]])
y = torch.gather(x, dim=1, index=mask_keep)
print(x)
# print(x.shape)
# print(mask_keep)
# print(mask_keep.shape)
print(y)
# print(y.shape)
all_y = []
all_y += [torch.gather(x, dim=1, index=mask_keep)]
print(all_y)
all_y += [torch.gather(x, dim=1, index=mask_keep)]
print(all_y)
print(torch.cat(all_y, dim=0))
print(torch.cat(all_y, dim=0).shape)



