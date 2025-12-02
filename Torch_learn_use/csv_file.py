import pandas as pd
import csv

headers = ['学号', '姓名', '分数']
rows = [('202001', '张三', '98'),
        ('202002', '李四', '95'),
        ('202003', '王五', '92')]
with open('./data/score.csv', 'w', encoding='utf8', newline='') as f:
    writer = csv.writer(f)
    writer.writerow(headers)
    writer.writerows(rows)
data_path = './data/score.csv'
data = pd.read_csv(data_path, header=None, delimiter=",")
print(data)
print(data.shape)
"""
        0   1   2
0      学号  姓名  分数
1  202001  张三  98
2  202002  李四  95
3  202003  王五  92
(4, 3)
"""
print(data.values[:, 0])
print(list(data.values[:, 0]))
"""
['学号' '202001' '202002' '202003']
['学号', '202001', '202002', '202003']
"""
print(list(data.values[:, 0]) + list(data.values[:, 1]))
"""
['学号', '202001', '202002', '202003', '姓名', '张三', '李四', '王五']
"""