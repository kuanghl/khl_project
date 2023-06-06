import json
import pandas
import csv
import os
import openpyxl
import ctypes 

def read_json(filename: str) -> dict:
    try:
        with open(filename, "r") as f:
            data = json.loads(f.read())
    except:
        raise Exception(f"Reading {filename} file encountered an error")
    return data


def auto_width(filename):
    # 打开xlsx文件
    wb = openpyxl.load_workbook(filename)
    # 遍历sheet
    for sheet in wb.sheetnames:
        ws = wb[sheet]
        df = pandas.read_excel(filename,sheet_name=sheet, engine='openpyxl')
        # 把表头改到最后一行
        df.loc[len(df)]=list(df.columns)
        for i in df.index:
            # 设置单元格对齐方式 Alignment(horizontal=水平对齐模式,vertical=垂直对齐模式,text_rotation=旋转角度,wrap_text=是否自动换行)
            alignment = openpyxl.styles.Alignment(horizontal='center', vertical='center', text_rotation=0, wrap_text=True)
            ws['A'+str(i+1)].alignment = alignment
            ws['B'+str(i+1)].alignment = alignment
            ws.row_dimensions[i].height = 20
        for col in df.columns:
            # 获取列序号
            index = list(df.columns).index(col)
            # 获取行字母表头
            letter = openpyxl.utils.get_column_letter(index+1)
            # 获取当前列最大宽度
            collen = df[col].apply(lambda x :len(str(x).encode())).max()
            # 设置列宽为最大长度比例
            ws.column_dimensions[letter].width = collen * 1.5
    wb.save(filename)

def main():
    # link c lib .so
    # perfinfo = ctypes.cdll.LoadLibrary(os.getcwd() + "/../libperfinfo.so")
    perfinfo = ctypes.cdll.LoadLibrary(os.path.dirname(__file__) + "/libperfinfo.so")

    # c string format transfer to python string
    perfinfo.getPlatform.restype = ctypes.c_char_p
    perfinfo.getMpulib.restype = ctypes.c_char_p
    perfinfo.getMps.restype = ctypes.c_char_p
    perfinfo.getDaemon.restype = ctypes.c_char_p


    # Read the JSON file as python dictionary 
    data = read_json(filename="src_acc_multi.json")

    # ansys data to format csv
    benchmarks_data = pandas.json_normalize(data, record_path =['benchmarks'])
    context_data = pandas.json_normalize(data, 
                                        record_path = [['context','caches']], 
                                        meta = [['context', 'date'], ['context', 'host_name'], ['context', 'executable'], ['context', 'num_cpus'], ['context', 'mhz_per_cpu'], ['context', 'cpu_scaling_enabled'], ['context', 'library_build_type']],
                                        errors='ignore')
    avg_data = pandas.json_normalize(data, record_path =[['context', 'load_avg']], errors='ignore')
    print(benchmarks_data);
    print(context_data);
    print(avg_data);


    # read data from outside. eg.env .so
    config = {
        "loglevel":[perfinfo.getLoglevel()],
        "platform":[perfinfo.getPlatform().decode("utf-8")],
        "mpulib":[perfinfo.getMpulib().decode("utf-8")],
        "mps":[perfinfo.getMps().decode("utf-8")],
        "daemon":[perfinfo.getDaemon().decode("utf-8")],
        "other":["other"],
        "path":[os.environ['HOME']],
        "name":['apple','egg','watermelon'],
        "color":['red','yellow','green'],
        "num":[30,40,50]
    }
    config_name_data = pandas.json_normalize(config, record_path =['name'], errors='ignore')
    config_color_data = pandas.json_normalize(config, record_path =['color'], errors='ignore')
    config_num_data = pandas.json_normalize(config, record_path =['num'], errors='ignore')
    config_list_data = pandas.json_normalize(config, meta = [['loglevel'], ['platform'], ['mpulib'], ['mps'], ['daemon'], ['other']],    
                                            errors='ignore')
    config_data = pandas.concat([config_name_data, config_color_data, config_num_data, config_list_data], axis = 1)
    print(config_data);


    # mode='a+': append to existing data
    context_data.to_csv('src_acc_multi.csv', index = False, encoding ='utf-8')
    avg_data.to_csv('src_acc_multi.csv', index = False, encoding ='utf-8', mode = 'a+', header = True)
    benchmarks_data.to_csv('src_acc_multi.csv', index = False, encoding ='utf-8', mode = 'a+', header = True)

    # # data into excel
    # excelfd = pandas.ExcelWriter('src_acc_multi.xlsx')
    # context_data.to_excel(excelfd, sheet_name = 'context')
    # avg_data.to_excel(excelfd, sheet_name = 'avg')
    # benchmarks_data.to_excel(excelfd, sheet_name = 'benchmarks')
    # excelfd.save()
    # excelfd.close()

    # data into excel
    with pandas.ExcelWriter('src_acc_multi.xlsx', engine='openpyxl') as excelfd:
        context_data.to_excel(excelfd, sheet_name = 'context', index = False)
        avg_data.to_excel(excelfd, sheet_name = 'avg', index = False)
        benchmarks_data.to_excel(excelfd, sheet_name = 'benchmarks')
        # add data into a sheet
        context_avg_data = pandas.concat([context_data, avg_data], axis = 1, keys = ['context', 'avg'], names = ['from', 'index_header'])
        context_avg_data.to_excel(excelfd, sheet_name = 'context_avg')
        # config data
        config_data.to_excel(excelfd, sheet_name = 'config')
    
    auto_width('src_acc_multi.xlsx')
        
if __name__ == '__main__':
    main()