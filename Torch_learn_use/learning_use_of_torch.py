import torch
from torch.distributions import Categorical

x = torch.randn(3, 2, 4)
y = torch.randn(3, 4)

print("x.shape = ", x.shape)
print("x = ", x)
print("x.size(-1) = ", x.size(-1))  # 返回x形状的最后一个维度
print("y.shape = ", y.shape)
print("y = ", y)

z = y.unsqueeze(1)
print("z.shape = ", z.shape)
print("z = ", z)

m = z.expand_as(x)
print("m.shape = ", m.shape)
print("m = ", m)

m_prod = torch.prod(m, 2)
print("m_prod.shape = ", m_prod.shape)
print("m_prod = ", m_prod)

m_prod_sum = torch.sum(m_prod, dim=1)
print("m_prod_sum.shape = ", m_prod_sum.shape)
print("m_prod_sum = ", m_prod_sum)

# 创建一个序列张量
sequence = torch.tensor([[[1, 2, 3], [4, 5, 6]],
                         [[9, 1, 3], [3, 5, 6]],
                         [[8, 2, 3], [4, 5, 7]]])
print("sequence.shape = ", sequence.shape)
# 创建一个索引张量
indices = torch.tensor([[[1]], [[0]], [[0]]])
print("indices.shape = ", indices.shape)
# 使用 torch.gather 选择序列中的元素
selected_elements = sequence.gather(dim=1, index=indices)
print(selected_elements)
"""Results:
sequence.shape =  torch.Size([3, 2, 3])
indices.shape =  torch.Size([3, 1, 1])
tensor([[[4]],

        [[9]],

        [[8]]])
"""

probs = torch.FloatTensor([[[0.05, 0.1, 0.85], [0.05, 0.05, 0.9], [0.4, 0.2, 0.4]],
                           [[0.05, 0.2, 0.75], [0.04, 0.06, 0.9], [0.2, 0.1, 0.7]],
                           [[0.03, 0.3, 0.67], [0.03, 0.07, 0.9], [0.2, 0.1, 0.7]]])
print("probs.shape = ", probs.shape)
dist = Categorical(probs)  # 分类分布
print("dist = ", dist)
index = dist.sample()
print("index = ", index)
print(index.numpy())
"""Results:
probs.shape =  torch.Size([3, 3, 3])
dist =  Categorical(probs: torch.Size([3, 3, 3]))
index =  tensor([[2, 2, 0],
        [2, 2, 2],
        [1, 2, 0]])
[[2 2 0]
 [2 2 2]
 [1 2 0]]
 """


""" Results : 
x.shape =  torch.Size([3, 2, 4])
x =  tensor([[[ 1.8170,  0.0703,  0.0650, -0.2000],
         [ 1.0800,  1.9706, -0.5862,  0.0473]],

        [[-0.4274,  0.8660, -1.1968, -0.0146],
         [-0.9035, -2.1493, -0.1598,  1.0977]],

        [[-0.4915, -1.1104,  1.9731,  2.8010],
         [ 0.7210, -0.6997, -1.0413, -0.2424]]])
x.size(-1) =  4
y.shape =  torch.Size([3, 4])
y =  tensor([[ 0.2869,  0.1655,  2.3830,  1.8314],
        [-0.7689,  0.8007, -0.0478,  0.1543],
        [ 0.7956, -1.1671,  0.6040,  1.6762]])
z.shape =  torch.Size([3, 1, 4])
z =  tensor([[[ 0.2869,  0.1655,  2.3830,  1.8314]],

        [[-0.7689,  0.8007, -0.0478,  0.1543]],

        [[ 0.7956, -1.1671,  0.6040,  1.6762]]])
m.shape =  torch.Size([3, 2, 4])
m =  tensor([[[ 0.2869,  0.1655,  2.3830,  1.8314],
         [ 0.2869,  0.1655,  2.3830,  1.8314]],     # 对上一行复制了一份

        [[-0.7689,  0.8007, -0.0478,  0.1543],
         [-0.7689,  0.8007, -0.0478,  0.1543]],     # 对上一行复制了一份

        [[ 0.7956, -1.1671,  0.6040,  1.6762],
         [ 0.7956, -1.1671,  0.6040,  1.6762]]])    # 对上一行复制了一份
m_prod.shape =  torch.Size([3, 2])
m_prod =  tensor([[-1.1179e-03, -1.1179e-03],
        [ 4.6435e+00,  4.6435e+00],
        [-8.3888e-03, -8.3888e-03]])
m_prod_sum.shape =  torch.Size([3])
m_prod_sum =  tensor([ 0.3374, -0.0155, -0.1318])

sequence.shape =  torch.Size([5])
tensor([10, 30, 50])

probs.shape =  torch.Size([2, 3])
probs =  tensor([[0.0500, 0.1000, 0.8500],
        [0.0500, 0.0500, 0.9000]])
dist =  Categorical(probs: torch.Size([2, 3]))
index =  tensor([2, 0])
[2 0]


the end"""


# 创建一个尺寸为(3, 1, 1)的张量
x = torch.tensor([[[1]], [[2]], [[3]]])
print("x = ", x)
print(x.size())  # 输出: torch.Size([1, 3, 1])
# 使用Torch squeeze函数删除尺寸为1的维度
y = torch.squeeze(x)  # 相当于从内而外剥除符号[]
print("y = ", y)
print(y.size())  # 输出: torch.Size([3])
"""Result : 
x =  tensor([[[1]],

        [[2]],

        [[3]]])
torch.Size([3, 1, 1])
y =  tensor([1, 2, 3])
torch.Size([3])
"""

# torch.view()用法
x = torch.tensor([1, 3, 5])
y = x.view(3, 1, 1)
print("x.shape = ", x.shape)
print("y = ", y)
print("y.shape = ", y.shape)
"""Results:
x.shape =  torch.Size([3])
y =  tensor([[[1]],

        [[3]],

        [[5]]])
y.shape =  torch.Size([3, 1, 1])
"""

# 张量乘法 A * B
A = torch.tensor([[1, 2, 3], [4, 5, 6]])
B = torch.tensor([1, 1, 0])
C = A * B
print("C = ", C)   # C = tensor([[1, 2, 0], [4, 5, 0]])

def translate_cluster(cluster, dim, amount):
    """Translates a cluster in a particular dimension by some amount
    torch.add_:
            一般来说函数加了下划线的属于内建函数，将要改变原来的值，没有加下划线的并不会改变原来的数据，
            引用时需要另外赋值给其他变量
    """
    translation = torch.ones(cluster.size(0)) * amount
    print("Translation = ", translation)
    cluster.transpose(0, 1)[dim].add_(translation)
    return cluster


cluster1 = torch.randn((4, 3)) / 4
print("cluster1 = ", cluster1)
cluster2 = translate_cluster(cluster1, 1, 1.2)
print("cluster2 = ", cluster2)
translation = torch.ones(4) * 1.2
cluster1.transpose(0, 1)[1].add_(translation)
print("cluster2 = ", cluster1)
