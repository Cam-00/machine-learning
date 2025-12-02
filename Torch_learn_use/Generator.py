import torch

# 每次运行的伪随机数结果都相同
seed = 2
g = torch.Generator()
# print(g)
# print(g.manual_seed(seed))
"""
<torch._C.Generator object at 0x000002B755FC34D0>
<torch._C.Generator object at 0x0000013312DE34D0>
"""
generator = g.manual_seed(seed)
_rand = torch.rand(1, generator=generator)
print(_rand)
print(_rand.size())
print(_rand.item())  # 只提取包含一个元素的张量的值
"""
tensor([0.6147])
torch.Size([1])
0.6146950721740723
"""
_rand = torch.rand(1, generator=generator)
print(_rand)
print(_rand.size())
print(_rand.item())

_rand = torch.rand(1, generator=generator)
print(_rand)
print(_rand.size())
print(_rand.item())