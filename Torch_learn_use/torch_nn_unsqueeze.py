import torch

x = torch.randn(2, 3)
print(x)
print(x.shape)
y = x.unsqueeze(1)
print(y)
print(y.shape)

"""
tensor([[ 1.3374,  1.6358, -0.5324],
        [-1.4034,  0.1463,  1.8126]])
torch.Size([2, 3])
tensor([[[ 1.3374,  1.6358, -0.5324]],

        [[-1.4034,  0.1463,  1.8126]]])
torch.Size([2, 1, 3])
"""