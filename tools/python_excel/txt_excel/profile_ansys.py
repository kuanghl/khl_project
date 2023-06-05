import re
import xlsxwriter
txt_url = r"./log2/yolov3_profile_time_new.txt"
sava_url = r'./log2/yolov3_profile_time_new.xlsx'

# 读取txt 并提取指定字符
def readTXT():
    with open(txt_url, 'r', encoding='utf-8') as f:
        content = f.read()  # 读取txt文件内容 保存到content中

    result1 = re.findall(".*xtime1 = (.*)us.*", content)  # 提取指定字符  表示提取 xtime1 = ~us.之间的字符
    result2 = re.findall(".*xtimes1 = (.*)num.*", content)  # 提取指定字符  表示提取 xtimes1 = ~num之间的字符
    result3 = re.findall(".*xtime2 = (.*)us.*", content)  # 提取指定字符  表示提取 xtime2 = ~us.之间的字符
    result4 = re.findall(".*xtimes2 = (.*)num.*", content)  # 提取指定字符  表示提取 xtimes2 = ~num之间的字符
    result5 = re.findall(".*sql_insert_time1 = (.*)us.*", content)  # 提取指定字符  表示提取 sql_insert_time1 = ~us.之间的字符
    result6 = re.findall(".*sql_insert_times1 = (.*)num.*", content)  # 提取指定字符  表示提取 sql_insert_time1 = ~num之间的字符 
    return result1, result2, result3, result4, result5, result6

def saveExcel(str1, str2, str3, str4, str5 ,str6):
    # todo 创建excel文件
    xl = xlsxwriter.Workbook(sava_url)
    # todo 添加sheet
    sheet = xl.add_worksheet('sheet1')
    k = 0
    j = 1
    # todo 往单元格cell添加数据,索引写入
    for i in range(len(str1)):
        # if i % 50 == 0:			# 数据50一组
        #     k = k + 4			# 每一组数据后 整体表格右移4格
        #     j = 0				# 每一组数据后 重新从0行 开始存入
        sheet.write_string(j, k, str1[i])	# j 表示行  k表示 列
        sheet.write_string(j, k + 1, str2[i]) #(excel从左上角开始算0行0列)
        sheet.write_string(j, k + 2, str3[i])	# j 表示行  k表示 列
        sheet.write_string(j, k + 3, str4[i]) #(excel从左上角开始算0行0列)
        j = j + 1				# 行+1 准备写入下一行

    # todo 往单元格cell添加数据,索引写入
    i = 0
    j = 1
    for i in range(len(str5)):
        # if i % 50 == 0:			# 数据50一组
        #     k = k + 4			# 每一组数据后 整体表格右移4格
        #     j = 0				# 每一组数据后 重新从0行 开始存入
        sheet.write_string(j, k + 4, str5[i])	# j 表示行  k表示 列
        sheet.write_string(j, k + 5, str6[i]) #(excel从左上角开始算0行0列)        
        j = j + 1				# 行+1 准备写入下一行
    
    # # todo 设置单元格宽度大小
    # sheet.set_column('A:B', 30)
    # todo 关闭文件
    xl.close()

str1, str2, str3, str4, str5, str6 = readTXT()
print('time1:',str1)
print('times1:',str2)
print('time2:',str3)
print('times2:',str4)
print('sql_insert_time1:',str5)
print('sql_insert_times1:',str6)
saveExcel(str1, str2, str3, str4, str5, str6)
