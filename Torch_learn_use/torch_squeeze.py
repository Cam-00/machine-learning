import torch

x = torch.randn(2, 3)
print(x)
print(x.shape)
y = x.squeeze(-1)  # 移除最后一个维度上大小为1的维度
print(y)
print(y.shape)

z = y.repeat(1, 1, 1, 2)
print(z)
print(z.shape)

"""
tensor([[ 1.5349, -0.8976, -0.7588],
        [-1.6523,  0.5807,  0.4006]])
torch.Size([2, 3])
tensor([[ 1.5349, -0.8976, -0.7588],
        [-1.6523,  0.5807,  0.4006]])
torch.Size([2, 3])
tensor([[[[ 1.5349, -0.8976, -0.7588,  1.5349, -0.8976, -0.7588],
          [-1.6523,  0.5807,  0.4006, -1.6523,  0.5807,  0.4006]]]])
torch.Size([1, 1, 2, 6])
"""