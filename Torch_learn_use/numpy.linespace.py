import numpy as np

start_idx = 0
end_idx = 10
fpc = 4
indices = np.linspace(start_idx, end_idx, num=fpc)
print(indices)
print(type(indices))
indices = np.clip(indices, start_idx, end_idx - 1)
print(indices)
print(type(indices))
indices = indices.astype(np.int64)
print(indices)
print(type(indices))