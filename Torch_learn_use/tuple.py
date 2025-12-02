import torch
import math

crop_size = 224
crop_size = (crop_size,) * 2
print(crop_size)
print(type(crop_size))

spatial_patch_size = 16
spatial_patch_size = (spatial_patch_size,) * 2
print(spatial_patch_size)

height, width = [crop_size[i] // spatial_patch_size[i] for i in (0, 1)]
print(height, width)

"""
(224, 224)
<class 'tuple'>
(16, 16)
14 14
"""