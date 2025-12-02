import torch
import numpy as np
# fpc_batch : 一个list, 元素为 tuple = (buffer, label, clip_indices)
fpc_batch = [([[7, 8], [9, 10]], 0, [np.array([1, 2, 7]), np.array([3, 4, 5])]),
             ([[6, 0], [0, 1]], 111, [np.array([4, 4, 4]), np.array([6, 8, 1])])]
collated_batch = torch.utils.data.default_collate(fpc_batch)
print(fpc_batch)
print(collated_batch)
print(type(fpc_batch[0]))
print(type(collated_batch))
print(collated_batch[2][0])

"""
[([[7, 8], [9, 10]], 0, [array([1, 2, 7]), array([3, 4, 5])]), ([[6, 0], [0, 1]], 111, [array([4, 4, 4]), array([6, 8, 1])])]
[[[tensor([7, 6]), tensor([8, 0])], [tensor([9, 0]), tensor([10,  1])]], tensor([  0, 111]), [tensor([[1, 2, 7],
        [4, 4, 4]], dtype=torch.int32), tensor([[3, 4, 5],
        [6, 8, 1]], dtype=torch.int32)]]
<class 'tuple'>
<class 'list'>
tensor([[1, 2, 7],
        [4, 4, 4]], dtype=torch.int32)
"""

import torch
from torch.utils.data import Dataset, DataLoader

print("PyTorch version:", torch.__version__)  # 应输出 2.0.0
print("DataLoader exists:", hasattr(torch.utils, 'data'))  # 应输出 True