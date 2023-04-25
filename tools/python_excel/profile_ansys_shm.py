import re
import xlsxwriter
txt_url = r"./yolov3_profile_time_shm.txt"
sava_url = r'./yolov3_profile_time_shm.xlsx'

# 读取txt 并提取指定字符
def readTXT():
    with open(txt_url, 'r', encoding='utf-8') as f:
        content = f.read()  # 读取txt文件内容 保存到content中

    result1 = re.findall(".*fill_time = (.*)us.*", content)  # 提取指定字符  表示提取 fill_time = ~us之间的字符
    result2 = re.findall(".*fill_times = (.*)num.*", content)  # 提取指定字符  表示提取 fill_times = ~num之间的字符
    result3 = re.findall(".*sql_insert_time = (.*)us.*", content)  # 提取指定字符  表示提取 sql_insert_time = ~us之间的字符
    result4 = re.findall(".*sql_insert_times = (.*)num.*", content)  # 提取指定字符  表示提取 sql_insert_time = ~num之间的字符 
    result5 = re.findall(".*s_msgid = (.*)num1,.*", content)  # 提取指定字符  表示提取 s_msgid = ~num1,之间的字符
    result6 = re.findall(".*dt_times = (.*)num2,.*", content)  # 提取指定字符  表示提取 dt_times = ~num2,之间的字符
    result7 = re.findall(".*dt1 = (.*)us1.*", content)  # 提取指定字符  表示提取 dt1 = ~us1之间的字符
    result8 = re.findall(".*dt2 = (.*)us2.*", content)  # 提取指定字符  表示提取 dt2 = ~us2之间的字符
    result9 = re.findall(".*dt3 = (.*)us3.*", content)  # 提取指定字符  表示提取 dt3 = ~us3之间的字符
    return result1, result2, result3, result4, result5, result6, result7, result8, result9

def saveExcel(str1, str2, str3, str4, str5 ,str6, str7, str8, str9):
    # todo 创建excel文件
    xl = xlsxwriter.Workbook(sava_url)
    # todo 添加sheet
    sheet = xl.add_worksheet('sheet1')
    k = 0
    j = 1
    # todo 往单元格cell添加数据,索引写入
    # sheet.write_string(行数, 列数, data)
    for i in range(len(str1)):
        sheet.write_string(j, k, str1[i])	# j 表示行  k表示 列
        sheet.write_string(j, k + 1, str2[i])   # j 表示行  k表示 列
        sheet.write_string(j, k + 2, str3[i])	# j 表示行  k表示 列
        sheet.write_string(j, k + 3, str4[i])   # j 表示行  k表示 列
        j = j + 1				# 行+1 准备写入下一行

    # todo 往单元格cell添加数据,索引写入
    i = 0
    j = 1
    # sheet.write_string(行数, 列数, data)
    for i in range(len(str5)):
        sheet.write_string(j, k + 4, str5[i])	# j 表示行  k表示 列
        sheet.write_string(j, k + 5, str6[i])   # j 表示行  k表示 列
        sheet.write_string(j, k + 6, str7[i])	# j 表示行  k表示 列
        sheet.write_string(j, k + 7, str8[i])   # j 表示行  k表示 列
        sheet.write_string(j, k + 8, str9[i])	# j 表示行  k表示 列
        j = j + 1				# 行+1 准备写入下一行
    
    # # todo 设置单元格宽度大小
    # sheet.set_column('A:B', 30)
    # todo 关闭文件
    xl.close()

str1, str2, str3, str4, str5, str6, str7, str8, str9 = readTXT()
print('fill time:',str1)
print('fill times:',str2)
print('sql_insert_time:',str3)
print('sql_insert_times:',str4)
print('msgid:',str5)
print('dt_times:',str6)
print('dt1:',str7)
print('dt2:',str8)
print('dt3:',str9)
saveExcel(str1, str2, str3, str4, str5, str6, str7, str8, str9)