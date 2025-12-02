import torch.nn as nn
import torch

x = torch.randn([5, 3, 6, 4, 4])
# print(x)
in_chans = 3
embed_dim = 7
tubelet_size = 3
patch_size = 2
proj = nn.Conv3d(
            in_channels=in_chans,
            out_channels=embed_dim,
            kernel_size=(tubelet_size, patch_size, patch_size),
            stride=(tubelet_size, patch_size, patch_size),
        )
x = proj(x)
print(x.shape)          # [5, 7, 2, 2, 2]
x_flatten = x.flatten(2)
print(x_flatten.shape)  # [5, 7, 8]
# print(x_flatten)
x_transpose = x_flatten.transpose(1, 2)
print(x_transpose.shape)   # [5, 8, 7]