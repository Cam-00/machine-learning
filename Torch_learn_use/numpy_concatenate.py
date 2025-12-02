import numpy as np

a = np.array([[1, 2, 3], [1, 1, 1]])
b = np.array([[2, 2, 2], [4, 5, 6]])
print(np.concatenate([a, b], axis=1))