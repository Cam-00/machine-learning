""".npy 文件格式"""
import numpy as np

arr = np.array([[1.0, 2.0, 3.0], [4.0, 5.0, 6.0]], dtype=np.float32)
np.save("./data/np_array.npy", arr)

# with open("./data/np_array.npy", "rb") as f:
#     print(np.load(f))
# """
# [[1. 2. 3.]
#  [4. 5. 6.]]
# """
data = np.load("./data/np_array.npy")
print(data)
print(type(data))  # <class 'numpy.ndarray'>
print(data.shape)  # (2, 3)
# map(...)：将匿名函数应用到data的每个元素上，返回一个迭代器
# repr(x)[1:-1]：将x转换为字符串表示形式, 并去掉字符串首尾引号, "'abc'"变为'abc'
# lambda x: repr(x)[1:-1] :  匿名函数，对每个x执行repr(x)[1:-1]
data0 = repr(data[0])
data1 = repr(data[1])
print(data0)
print(data1)
print(data)
print(map(lambda x: repr(x)[1:-1], data))
print(type(map(lambda x: repr(x)[1:-1], data)))
print(data)
b = list(map(lambda x: repr(x)[1:-1], data))
print(type(b))  # <class 'list'>

print(data)
print(b)
"""
<map object at 0x000001C661C6A520>
['rray([1., 2., 3.], dtype=float32', 'rray([4., 5., 6.], dtype=float32']
"""

labels = [0] * len(data)
print(labels)
"""
[0, 0]
"""
print(isinstance(b, list))  # True
if not isinstance(b, str):
    print('Error!')  # Error!
