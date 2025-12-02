import numpy as np
embed_dim = 4
pos_embed = np.array([[2, 3, 4, 5]])
print(pos_embed.shape)  # (1, 4)
pos_embed = np.concatenate([np.zeros([1, embed_dim]), pos_embed], axis=0)
print(pos_embed.shape)  # (2, 4)
print(pos_embed)
"""
pos_embed = 
[[0. 0. 0. 0.]
 [2. 3. 4. 5.]]
"""