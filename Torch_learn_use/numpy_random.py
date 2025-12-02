import numpy as np

print(np.random.randint(2, 6))
indices = np.linspace(0, 4, num=3)
print(indices)
indices = np.clip(indices, 0, 4 - 1)
print(indices)