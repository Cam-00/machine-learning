from multiprocessing import Value
x = Value("i", -1)
print(x.value)
y = x
with y.get_lock():
    y.value += 3
print(y.value)
print(x.value)
"""
-1
2
2
"""