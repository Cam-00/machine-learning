import torch

# 初始化两组参数
params_k = [torch.randn(3, 3) for _ in range(2)]  # 目标参数
params_q = [torch.ones(3, 3) for _ in range(2)]   # 源参数
m = 0.9  # 动量系数
print(params_k)
print(params_q)
# 执行操作：params_k += (1 - m) * params_q
torch._foreach_add_(params_k, params_q, alpha=1 - m)
print(params_k)
print(params_q)
