### google benchmark/gbenchmark性能测试平台.
- [x] benchmark--clone google benchmark源码.
- [x] gbenchmark--google benchmark release版本.
- [x] common_pref--放置通用函数API性能测试集.
- [x] gbenchmark WARNING处理： 
  - [x] CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.
        
      ```
      cpupower
      sudo apt install -y linux-tools-5.13.0-1031-aws linux-tools-common
      sudo apt-get install -y linux-tools-common
      sudo apt-get install cpufrequtils
      sudo apt-get install linux-cpupower
      # 性能模式下警告消失
      sudo cpupower frequency-set --governor performance 
      # 非性能模式下警告出现
      sudo cpupower frequency-set --governor ondemand
      Usage:  cpupower [-d|--debug] [-c|--cpu cpulist ] <command> [<args>]
      Supported commands are:
              frequency-info
              frequency-set
              idle-info
              idle-set
              set
              info
              monitor
              help
      ```
  - [ ] Library was built as DEBUG. Timings may be affected.
        ```
        
        ```