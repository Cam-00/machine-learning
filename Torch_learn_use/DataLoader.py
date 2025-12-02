import torch
from torch.utils.data import DataLoader

data_loader = torch.utils.data.DataLoader(
            dataset,
            collate_fn=collator,
            sampler=dist_sampler,
            batch_size=batch_size,
            drop_last=drop_last,
            pin_memory=pin_mem,
            num_workers=num_workers,
            persistent_workers=(num_workers > 0) and persistent_workers,
        )
loader = iter(data_loader)
sample = next(loader)
for _fpc_sample in sample:
    bs, fpc = _fpc_sample[0][-1][0].size()
