import numpy as np

d = np.array([0, 1, 2])
h = np.array([0, 1, 2, 3])
w = np.array([0, 1, 2, 3, 4])
h, d, w = np.meshgrid(h, d, w)   # 结果与 np.meshgrid(d, h, w) 不同
print(h)
print(h.shape)
print(d)
print(d.shape)
print(w)
print(w.shape)

d, h, w = np.meshgrid(d, h, w)
print(h)
print(h.shape)
print(d)
print(d.shape)
print(w)
print(w.shape)