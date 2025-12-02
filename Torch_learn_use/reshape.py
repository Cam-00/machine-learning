import torch

x = torch.arange(0, 12)
print(x)
print(x.untyped_storage().data_ptr())
y = x.view(2, 6)
print(y)
print(y.untyped_storage().data_ptr())
z = x.reshape(2, 6)
print(z)
print(z.untyped_storage().data_ptr())
# 上面 x y z 共享一个内存

# yt = y.T
# print(yt)
# yt = yt.view(2, 2, 3)
# print(yt)
zt = z.T  # zt 内存地址没改变, 与z共享内存
print(zt.is_contiguous())
print(zt)
print(zt.untyped_storage().data_ptr())
# torch.contiguous()方法首先拷贝了一份张量在内存中的地址，
# 然后将地址按照形状改变后的张量的语义进行排列
zt = zt.contiguous()   # zt 内存地址改变了
print("after contiguous view: ", zt)
print(zt.untyped_storage().data_ptr())
zt = zt.reshape(2, 3, 2)
print(zt)
print(zt.untyped_storage().data_ptr())
