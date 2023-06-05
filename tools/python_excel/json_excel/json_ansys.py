#!/usr/bin/python3
# -*- coding: utf-8 -*-

import json
import tablib

# json.text文件的格式： [{"a":1},{"a":2},{"a":3},{"a":4},{"a":5}]

##################json
# 获取ｊｓｏｎ数据
with open('data3.json', 'r') as f:
    rows = json.load(f)

# 将json中的key作为header, 也可以自定义header（列名）
header=tuple([ i for i in rows[0].keys()])

data = []
# 循环里面的字典，将value作为数据写入进去
for row in rows:
    body = []
    for v in row.values():
        body.append(v)
    data.append(tuple(body))

data = tablib.Dataset(*data,headers=header)

open('data4.xlsx', 'wb').write(data.xlsx)

########################csv
import csv
with open('data3.json', 'r') as f:
    rows = json.load(f)
# 创建文件对象
f = open('data4.csv', 'w')

# 通过文件创建csv对象
csv_write = csv.writer(f)

# writerow: 按行写入，　writerows: 是批量写入
# 写入数据 取列表的第一行字典，用字典的ｋｅｙ值做为头行数据
csv_write.writerow(rows[0].keys())

# 循环里面的字典，将value作为数据写入进去
for row in rows:
    csv_write.writerow(row.values())
    
# 关闭打开的文件
f.close()

