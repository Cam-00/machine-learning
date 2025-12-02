import torch

a = torch.randn(1, 2, 3)
b= torch.randn(4, 2, 3)
# 将a的每个元素依次加到b的对应位置
c = a + b
print(c.shape)  # [4, 2, 3]
print(a)
print(b)
print(c)