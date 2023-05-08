- [Demo study environment.](#demo-study-environment)
  - [1. 3rd develop](#1-3rd-develop)
  - [2. gtest/gbenchmark](#2-gtestgbenchmark)
  - [3. linux c](#3-linux-c)
  - [4. network](#4-network)
  - [5. data struct](#5-data-struct)
  - [6. 编译及使用方法](#6-编译及使用方法)
  - [7. Request and Push.](#7-request-and-push)

## Demo study environment.
嵌入式C/C++多平台开发学习平台，可以用于开发前测试及积累。综合多种高效库及架构，适用于个人学习及移植使用。

### 1. 3rd develop
三方库引用x86/Risv平台，Linux环境下开发。
- libuv
- liteos-a

### 2. gtest/gbenchmark
- google test单元测试平台搭建及使用。
  ```
  cd build
  # 整个测试集
  ./test/common_test/common_test --gtest_filter=CommonTest*
  # 单个测试例
  ./test/common_test/common_test --gtest_filter=CommonTest.Negative
  ```
- google benchmark单元性能测试平台搭建及使用。
  ```
  # 列出所有测试例
  ./pref/common_pref/common_pref --benchmark_list_tests=ture
  # 执行所有测试例
  ./pref/common_pref/common_pref --benchmark_list_tests=false
  # 执行指定测试项
  ./pref/common_pref/common_pref --benchmark_filter=factorial_pref_xx
  # 设置输出格式
  ./pref/common_pref/common_pref --benchmark_format=<console | json | csv>
  # 输出到指定文件
  ./pref/common_pref/common_pref --benchmark_out=<filename>
  # 显示计数器参数
  ./pref/common_pref/common_pref --benchmark_counters_tabular=true
  ```


### 3. linux c
linux 相关库函数及POSIX标准函数使用及积累。

### 4. network
网络相关的内容学习及运用。

### 5. data struct
数据结构及算法通用库构建。

### 6. 编译及使用方法
cmake整项目编译指令流程：
- `loglevel`整个项目的log打印级数
- `logcolor_en`整个项目的log颜色使能
- `gtest_en = on`使用gtest release-1.12.1.zip包,`gtest_en = off`使用clone googletest源码编译
- `mps_en`网络模式及单机模式切换
- `daemon`网络连接控制多用户/单用户
```
mkdir build
cd build
cmake .. -Dloglevel=5 -Dlogcolor_en=on -Dgtest_en=off -Dmps_en=off -Ddaemon=off
make -j16
sudo make install
```

### 7. Request and Push.
