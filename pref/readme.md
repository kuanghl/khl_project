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
***

### gperftools.
- [x] gperftools use demo--gperftools clone from master/ggperftools from release.
- [x] src/server/server_main.c--测试集
- [x] 环境测试和测试详情：
    ```
    # install gperftools.
    sudo apt-get install libunwind-dev
    sudo apt install ghostscript -y
    sudo apt-get install graphviz -y
    wget https://github.com/gperftools/gperftools/archive/master.zip
    unzip master
    cd gperftools-master
    ./autogen.sh
    ./configure
    make
    make install
    
    # code test.
    export LD_LIBRARY_PATH=/usr/local/lib
    export PATH=$PATH:/usr/local/bin
    ./server
    pprof --text server server.prof
    pprof --pdf server server.prof > server.pdf
    ```
***

### nanobench.
- [x] config and democode.
  - 前置环境：
  ```
  perf stat
  sudo apt-get install linux-tools-5.15.0-71-generic
  cat /proc/sys/kernel/perf_event_paranoid
  # ref https://www.kernel.org/doc/html/latest/admin-guide/perf-security.html
  ```
  - democode:
  ```c
  // #define ANKERL_NANOBENCH_IMPLEMENT
  #include <nanobench.h>

  int main() {
      double d = 1.0;
      ankerl::nanobench::Bench().run("some double ops", [&] {
          d += 1.0 / d;
          if (d > 5.0) {
              d -= 5.0;
          }
          ankerl::nanobench::doNotOptimizeAway(d);
      });
  }
  ```
- [x] result.
- [x] error fix.
  - 显示参数过少：
  case0: `#define ANKERL_NANOBENCH_IMPLEMENT` 为安装模式使用，cmake外部项目不使用。
  case1: ![img](https://img2023.cnblogs.com/blog/2516406/202305/2516406-20230519162342118-1592625284.png)
  case2: 权限不足，应该使用sudo/su root权限执行对应测试程序。

```
```
***

### other.
- `time ./bin/server`--获取real/user/sys程序占用时间ms
- `/usr/bin/time ./bin/server`--获取real/user/sys程序占用时间s及更多信息