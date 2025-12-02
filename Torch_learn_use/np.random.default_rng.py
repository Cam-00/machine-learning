import numpy as np

seed = 2
epoch = 1
# deterministically shuffle based on epoch and seed
rng = np.random.default_rng(seed + epoch)  # 创建随机数生成器实例
# 从给定数组生成随机数
total_size = 6
sample_probabilities = [0.1, 0, 0.3, 0.6, 0]
indices = rng.choice(
    range(0, 5),   # 从其元素中生成随机样本
    size=total_size,   # 实际需求总样本数大小：self.total_size = self.num_samples(单卡样本数) * self.num_replicas(卡数)
    p=sample_probabilities,  # 与range(0, n)中每个元素关联的概率，形状与输入相同。如果未给出，则样本假定 range(0, n) 中所有元素具有均匀分布
    replace=True,  # 样本是否带回放
).tolist()
print(indices)   # 每次运行, 结果都是[0, 2, 3, 3, 0, 3]