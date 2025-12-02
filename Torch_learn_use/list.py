# import numpy as np
# a = [1,2,3,4,5,6,7,8,9]
# print(type(a))  # <class 'list'>
# b = [10, 20, 30, 40, 50, 60, 70]
# a += b
# print(a)  # [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50, 60, 70]
#
# c = []
# x = np.linspace(1, 4, 5, dtype=int)
# print(x)   # [1 1 2 3 4]
# x = np.concatenate((x, np.ones(2) * 3))
# print(x)   # [1. 1. 2. 3. 4. 3. 3.]
# y = np.linspace(4, 8, 2, dtype=int).astype(np.int64)
# c.append(x.astype(np.int64))
# c.append(y)
# print(y)  # [4 8]
# print(type(x))  # <class 'numpy.ndarray'>
# print(c)
#
# d = [a[i * 2 : (i + 1) * 2] for i in range(8)]
# print(d)
#
# print(b * 3)  # 将列表b中的元素 复制 3次
# print(a)
# print(a[0:16:4])  # [1, 5, 9, 40]
# print(a[2:16:4])
# print(a[:0])
# a += a[:0]
# print(a)
# print(a[:16])

import torch
x = []
x += [[torch.randint(0, 9, [3, 2, 3])]]
print("x = ", x)
x += [[torch.randint(0, 9, [3, 2, 3])]]
print("x = ", x)

y = [torch.randint(0, 9, [2, 2]), torch.randint(0, 9, [2, 2])]
outs = [[] for _ in y]
print(outs)


a = [1, 2, 3, 4, 5]
b = torch.tensor(a)
print("b = ", b)
print(b.square())
print(b.square().sum(dim=0))
c = b.square().sum().sqrt()
print("c = ", c)