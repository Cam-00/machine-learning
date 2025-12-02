import torch
import torch.nn as nn

# Compute scale factor for spatio-temporal interpolation
T, H, W = [4, 6, 6]
N_t, N_h, N_w = [2, 3, 3]
dim = 5
scale_factor = (T / N_t, H / N_h, W / N_w)

pos_embed = nn.functional.interpolate(
    torch.randn(1, N_t, N_h, N_w, dim).permute(0, 4, 1, 2, 3),
    scale_factor=scale_factor,
    mode="nearest",  # trilinear
)
print(pos_embed.shape)
print(pos_embed)