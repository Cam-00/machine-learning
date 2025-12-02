import torch
cm = torch.tensor([2, 0, 1, 4, 7])
cm_full_complement = torch.tensor(
                        sorted(list(set(range(int(2 * 4 * 4))) - set(cm.tolist()))),
                        dtype=cm.dtype,
                        )
print(set(cm.tolist()))
print(range(int(2 * 4 * 4)))
print(set(range(int(2 * 4 * 4))))
print(set(range(int(2 * 4 * 4))) - set(cm.tolist()))
print(list(set(range(int(2 * 4 * 4))) - set(cm.tolist())))
print(cm_full_complement)

ema = [0.99000, 0.99925]
ipe = 300
num_epochs = 10
ipe_scale = 1.25
momentum_scheduler = (
        ema[0] + i * (ema[1] - ema[0]) / (ipe * num_epochs * ipe_scale)
        for i in range(int(ipe * num_epochs * ipe_scale) + 1)
    )
print(next(momentum_scheduler))

a = (i for i in range(int(2 * 4 * 4)))
for i in range(int(2 * 4 * 4)):
    print(next(a))