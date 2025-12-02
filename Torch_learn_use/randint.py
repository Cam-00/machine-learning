import torch

t, h, w = [2, 3, 2]
# print(t, h, w)
top = torch.randint(0, 6 - h + 1, (1,))
left = torch.randint(0, 6 - w + 1, (1,))
start = torch.randint(0, 2 - t + 1, (1,))
print(start,top, left)

# 构造一个掩码矩阵，元素只有 0 1
mask = torch.ones((2, 6, 6), dtype=torch.int32)
mask[start : start + t, top : top + h, left : left + w] = 0
print(mask)
