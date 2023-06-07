import json
import pandas
import csv
import os
import openpyxl
import ctypes 
import argparse
import sys
import numpy
import matplotlib
import matplotlib.pyplot
import scipy
import scipy.stats
import textwrap


# 判断是否为路径
def is_dir(file_path):
    directory = os.path.dirname(file_path)
    if not os.path.exists(directory):
        os.makedirs(directory)

# 指令输入及传出
def cmd_inter():
    # 创建一个ArgumentParser的对象，此对象包含将命令行参数解析为 python 数据类型所需的全部信息。
    parser = argparse.ArgumentParser(description='Generates the json of google benchmark to csv/excel/polt.', add_help=True)
    # 添加参数命令
    parser.add_argument('-i', '--input', help="Input .json files directory.")
    parser.add_argument('-o', '--output', help="Output .csv/.xlsx/.png files directory.")
    parser.add_argument('-l', '--link', help="Link c/c++ libraries directory.")
    parser.add_argument('-m', '--mode', help="Output all/simple content to .csv/.xlsx/.png.", default=["simple"])
    parser.add_argument('-s', '--select', help="Select the output files from csv/xlsx/png.", default=["csv", "xlsx", "png"], nargs="*")
    parser.add_argument('-f', '--format', help="The benchmark metric(s) format to track.", default=["name", "cpu_time", "real_time", "iterations"], nargs="*")
    parser.add_argument('-n', '--name', help=".json files name.", default=["all"])

    # 初步解析参数命令
    args = parser.parse_args()
    if args.input is None:
        args.input = os.getcwd()

    if args.output is None:
        args.output = os.getcwd()
        is_dir(args.output)
    
    if args.link is None:
        args.link = os.path.dirname(__file__)
    print(args)
    return args

# 扫描路径下的所有文件类型
def scan_filetype(directory, filetype):
    files = []
    for entry in os.scandir(directory):
        if entry.path.endswith(filetype) and entry.is_file():
            files.append(entry)
    if len(files) == 0:
        print('Error no such file type! ')
    return files, entry


def read_json(filename: str) -> dict:
    try:
        with open(filename, "r") as f:
            data = json.loads(f.read())
    except:
        raise Exception(f"Reading {filename} file encountered an error")
    return data

def analysis_file(file, benchmarks, metric):
    print('analysis ' + file)
    data = read_json(file)
    print('\t' + data['context']['date'])
    print('\t' + data['context']['host_name'])
    print('\t' + data['context']['executable'])
    print('\t' + '%d' %data['context']['num_cpus'])
    print('\t' + '%d' %data['context']['mhz_per_cpu'])
    print('\t' + '%s' %data['context']['cpu_scaling_enabled'])
    for a in data['context']['caches']:
        print('\t' + a['type'])
        print('\t' + '%d' %a['level'])
        print('\t' + '%d' %a['size'])
        print('\t' + '%d' %a['num_sharing'])
    print('\t' + '%s' %data['context']['load_avg'][0])
    print('\t' + '%s' %data['context']['load_avg'][1])
    print('\t' + '%s' %data['context']['load_avg'][2])
    print('\t' + data['context']['library_build_type'])

    for b in data['benchmarks']:
        print('\t' + b['name'] + "." + metric + ' = ' + str(b[metric]))
        if benchmarks.get(b['name']) is None:
            benchmarks[b['name']] = [b[metric]]
        else:
            benchmarks[b['name']].append(b[metric])

def smooth(x,window_len=11,window='hanning'):
    # references: https://scipy-cookbook.readthedocs.io/items/SignalSmooth.html
    if x.ndim != 1:
        raise ValueError("smooth only accepts 1 dimension arrays.")

    if x.size < window_len:
        raise ValueError("Input vector needs to be bigger than window size.")

    if window_len<3:
        return x

    if not window in ['flat', 'hanning', 'hamming', 'bartlett', 'blackman']:
        raise ValueError("Window is on of 'flat', 'hanning', 'hamming', 'bartlett', 'blackman'")

    s=numpy.r_[x[window_len-1:0:-1],x,x[-2:-window_len-1:-1]]
    if window == 'flat': #moving average
        w=numpy.ones(window_len,'d')
    else:
        w=eval('np.'+window+'(window_len)')

    y=numpy.convolve(w/w.sum(),s,mode='valid')
    return y[0:len(x)]  

def hasSlowedDown(benchmark, raw_values, smoothedvalues, slidingwindow, alphavalue, metric):
    sample_count = len(raw_values)
    sample_a_len = sample_count - slidingwindow
    sample_b_len = slidingwindow

    # mw test
    sample_a = smoothedvalues[:sample_a_len]
    sample_b = smoothedvalues[sample_a_len:]
    print('len(sample_a) = ' + str(len(sample_a)) + ' len(sample_b) = ' + str(len(sample_b)))
    stat, p = scipy.stats.mannwhitneyu(sample_a, sample_b)
    print('BENCHMARK ' + benchmark + ' STATS=%.3f, p=%.3f' % (stat, p))
    if p < alphavalue:
        print('\tStep change possibly found, performing t-test...')
        
        # confirm with Welch's t-test as mw can reject if sd is big (see: https://thestatsgeek.com/2014/04/12/is-the-wilcoxon-mann-whitney-test-a-good-non-parametric-alternative-to-the-t-test/)
        stat, p = scipy.stats.ttest_ind(sample_a, sample_b, equal_var = False)
        if p < alphavalue:
            return True;
        print('\tStep change doesnt appear to be part of a trend')
    return False 

def turningpoints(x):
    peaks = []
    troughs = []
    for i in range(1, len(x)-1):
        if (x[i-1] < x[i] and x[i+1] < x[i]):
            peaks.append(i)
        elif (x[i-1] > x[i] and x[i+1] > x[i]):
            troughs.append(i)
    return peaks, troughs


def estimateStepLocation(values):
    # references: https://stackoverflow.com/questions/48000663/step-detection-in-one-dimensional-data/48001937)
    dary = numpy.array(values)
    avg = numpy.average(dary)
    dary -= avg
    step = numpy.hstack((numpy.ones(len(dary)), -1*numpy.ones(len(dary))))
    dary_step = numpy.convolve(dary, step, mode='valid')
    print(numpy.argmax(dary_step))

    # get location of step change
    peaks, troughs = turningpoints(dary_step)
    if(len(peaks)) == 0:
        return 0;

    step_max_idx = peaks[-1]
    return step_max_idx

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
    # cmd
    args = cmd_inter()
    print(len(args.format))

    # get list of files to parse
    files, entry = scan_filetype(args.input, ".json")
    print(entry.path)
    print(files)

    # 文件按时间排序
    files.sort(key=os.path.getmtime)

    # 选择所有文件中的几个
    print(len(files))
    print(files[0:1])
    print(files[:len(files)-(3)])

    metrics = args.format
    for metric in metrics:
        benchmarks = {}
        for entry in files:
            if entry.path.endswith('.json') and entry.is_file():
                try:
                    analysis_file(entry.path, benchmarks, metric)
                except:
                    print('Corrupt benchmark file encountered, skipping...')
        for benchmark in benchmarks:
            raw_values = benchmarks[benchmark]
            sample_count = len(raw_values)
            print(str(sample_count))
            print(benchmark)

            # apply a median filter to the data to smooth out temporary spikes
            smoothedValues = smooth(numpy.array(raw_values), 1)
            print(str(smoothedValues))
            print(str(numpy.array(raw_values)))

            # plot raw and smoothed values
            matplotlib.pyplot.plot(raw_values, '-g', label="raw")
            matplotlib.pyplot.plot(smoothedValues, '-b', label="smoothed")
            matplotlib.pyplot.ylabel(metric)
            matplotlib.pyplot.xlabel('sample #')

            # plot line fit
            x_vals  = numpy.arange(0, len(raw_values), 1)
            y_vals  = raw_values
            model   = numpy.polyfit(x_vals, y_vals, 1)
            predict = numpy.poly1d(model)
            lrx     = range(0, len(x_vals))
            lry     = predict(lrx)
            matplotlib.pyplot.plot(lrx, lry, 'tab:orange', label="linear regression")

            # has it slowed down?
            if 1 and hasSlowedDown(benchmark, raw_values, smoothedValues, 6, 0.05, metric):
           
                # estimate step location
                step_max_idx  = estimateStepLocation(smoothedValues)
                if step_max_idx > 0 and step_max_idx < sample_count:
                    print('step_max_idx = ' + str(step_max_idx))
                    if (smoothedValues[step_max_idx+1] > smoothedValues[step_max_idx-1]):
                        print('\tBENCHMARK ' + benchmark + ' STEP CHANGE IN PERFORMANCE ENCOUNTERED (SLOWDOWN) - likely occurred somewhere between this build and this build minus ' + str(sample_count - step_max_idx) + ']')
                        
                        # plot step location
                        matplotlib.pyplot.plot((step_max_idx, step_max_idx), (numpy.min(raw_values), numpy.max(raw_values)), 'r', label="slowdown location estimation")
                    else:
                        print('\tBENCHMARK ' + benchmark + ' STEP CHANGE IN PERFORMANCE ENCOUNTERED (SPEEDUP) - ignoring')
                else:
                    print('\tBENCHMARK ' + benchmark + ' step index is 0 - likely speedup, ignoring')

            matplotlib.pyplot.title('\n'.join(textwrap.wrap(benchmark, 50)))
            matplotlib.pyplot.legend(loc="upper left")
            figurePath = os.path.join(args.output, benchmark+"-"+metric+".png")
            is_dir(figurePath)
            matplotlib.pyplot.tight_layout()
            matplotlib.pyplot.savefig(figurePath)
            matplotlib.pyplot.clf()
            plotItem = dict(path=os.path.relpath(figurePath, args.output))
            plots = []
            plots.append(plotItem)

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