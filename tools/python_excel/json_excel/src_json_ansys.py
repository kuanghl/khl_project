import json
import pandas
import csv

def read_json(filename: str) -> dict:
    try:
        with open(filename, "r") as f:
            data = json.loads(f.read())
    except:
        raise Exception(f"Reading {filename} file encountered an error")
    return data

def main():
    # Read the JSON file as python dictionary 
    data = read_json(filename="src_acc_multi.json")

    # ansys data to format csv
    benchmarks_data = pandas.json_normalize(data, record_path =['benchmarks'])
    context_data = pandas.json_normalize(data, 
                                        record_path = [['context','caches']], 
                                        meta = [['context', 'date'], ['context', 'host_name'], ['context', 'executable'], ['context', 'num_cpus'], ['context', 'mhz_per_cpu'], ['context', 'cpu_scaling_enabled'], ['context', 'library_build_type']],
                                        errors='ignore')
    avg_data = pandas.json_normalize(data, record_path =['context', 'load_avg'], errors='ignore')
    print(benchmarks_data);
    print(context_data);
    print(avg_data);

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
    with pandas.ExcelWriter('src_acc_multi.xlsx') as excelfd:
        context_data.to_excel(excelfd, sheet_name = 'context')
        avg_data.to_excel(excelfd, sheet_name = 'avg')
        benchmarks_data.to_excel(excelfd, sheet_name = 'benchmarks')

if __name__ == '__main__':
    main()