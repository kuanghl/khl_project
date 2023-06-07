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

def main():
    # # link c lib .so
    # perfinfo = ctypes.cdll.LoadLibrary(os.getcwd() + "/../libperfinfo.so")
    # perfinfo = ctypes.cdll.LoadLibrary(os.path.dirname(__file__) + "/../libperfinfo.so")

    # # c string format transfer to python string
    # perfinfo.getPlatform.restype = ctypes.c_char_p
    # perfinfo.getMpulib.restype = ctypes.c_char_p
    # perfinfo.getMps.restype = ctypes.c_char_p
    # perfinfo.getDaemon.restype = ctypes.c_char_p


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
        "loglevel":[1],
        "platform":["RPP"],
        "mpulib":["on"],
        "mps":["off"],
        "daemon":["on"],
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
        # merge data and add data into a sheet
        context_avg_data = pandas.concat([context_data, avg_data], axis = 1, keys = ['context', 'avg'], names = ['from', 'index_header'])
        context_avg_data.to_excel(excelfd, sheet_name = 'context_avg')
        # config data
        config_data.to_excel(excelfd, sheet_name = 'config')
        
if __name__ == '__main__':
    main()