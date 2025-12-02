import numpy as np

embed_dim = 10
omega = np.arange(embed_dim // 2, dtype=float)
print(omega)
omega /= embed_dim / 2.0
print(omega)
omega = 1.0 / 10000**omega  # (D/2,)
print(omega)
pos = np.arange(6, dtype=int)
out = np.einsum("m,d->md", pos, omega)  # (M, D/2), outer product
print(out)