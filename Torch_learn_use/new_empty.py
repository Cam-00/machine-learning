import torch
x = torch.randint(0, 10, (2, 2, 3))
print(x)
shape = (x.shape[0],) + (1,) * (x.ndim - 1)
print(shape)
print(type(shape))
keep_prob = 0.3
random_tensor = x.new_empty(shape).bernoulli_(keep_prob)
print(random_tensor)
print(x * random_tensor)