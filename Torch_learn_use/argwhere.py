import torch

mask = torch.ones([3, 2, 3])
# print(mask)
mask[1:3, 0:1, 1:3] = 0
print(mask)
mask = mask.flatten()
print(mask)
mask_e = torch.argwhere(mask == 0)
print(mask_e)
print(mask_e.size())
mask_e = mask_e.squeeze()
# mask_e = mask_e.flatten()
print(mask_e)
print(mask_e.size())
collated_masks_enc = []
collated_masks_enc.append(mask_e)
mask_p = torch.nonzero(mask).squeeze()
print(mask_p)
collated_masks_enc.append(mask_p)
print(collated_masks_enc)
collated_masks_enc = [cm[:3] for cm in collated_masks_enc]
print(collated_masks_enc)
collated_masks_enc = torch.utils.data.default_collate(collated_masks_enc)
print(collated_masks_enc)

# mask_e = torch.randint(0, 10, [2, 3, 1])
# print(mask_e)
# mask_e = mask_e.squeeze()
# print(mask_e)
# print(mask_e.size())

