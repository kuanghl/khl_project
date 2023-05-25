- [Demo study environment.](#demo-study-environment)
  - [1. 3rd develop](#1-3rd-develop)
  - [2. gtest/gbenchmark](#2-gtestgbenchmark)
  - [3. linux c](#3-linux-c)
  - [4. network](#4-network)
  - [5. data struct](#5-data-struct)
  - [6. 编译及使用方法](#6-编译及使用方法)
  - [7.docker部署与使用](#7docker部署与使用)
  - [8. Request and Push](#8-request-and-push)

## Demo study environment.
嵌入式C/C++多平台开发学习平台，可以用于开发前测试及积累。综合多种高效库及架构，适用于个人学习及移植使用。
- 3rd--三方库引用
- build--编译目标项目文件夹
- docker--docker镜像构建及验证
- cfun--linux c及标准c函数测试验证
- fun--系统/网络开发及一些编程模型
  - device--kernel到user驱动
  - libuv--libuv demo coding
  - modules--编程模型
  - primary--linux下默认库函数编程
- include--本项目标准api头
- kernel--linux kernel学习使用
- lib--编译库及外部库
- log--阻塞/异步日志
  - simple_log--同步阻塞日志
- notes--学习笔记及demo code
  - cuda--cuda api学习笔记及参考
  - git--git使用流程笔记
  - linux-note--linux下开发相关笔记
    - cpp-primer-5th--c++学习基础资料
    - data-algo--数据结构与算法相关资料(暂未整理)
    - ldd3--linux device driver设备驱动开发
    - linux-api--linux环境下基本api
    - linux操作系统--linux操作系统架构概述及基本知识叙述
    - linux网络编程--linux下网络编程模型基础讲解
    - linux系统编程手册--linux系统编程详解
    - linux性能优化--linux性能优化方向基本讲解
    - POSIX-threads--posix线程精讲
    - tcp-ip网络编程--tcp/ip网络编程详解
    - Unix环境高级编程--UNIX环境编程基础
  - unix-note--UNIX环境下demo code及讲解
- pref--google benchmark性能测试基本框架
- src--项目开发代码
- test--google test单元测试基本框架
- tools--单元测试/回归测试及其他python工具

### 1. 3rd develop
三方库引用x86/Risv平台，Linux环境下开发。
- libuv
- liteos-a
- gtest
- doctest-fakeilt
- gbenchmark
- gperftools
- nanobench

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
linux 相关库函数system V系统已编译内核标准及POSIX标准函数使用及积累。

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
- `daemon_en`网络连接控制多用户/单用户
- `gbenchmark = other`使用release benchmark-1.7.1.zip,`gbenchmark = off`使用clone google benchmark源码编译
```
mkdir build
cd build
cmake .. -Dloglevel=5 -Dlogcolor_en=on -Dgtest_en=off -Dmps_en=off -Ddaemon=off
make -j16
sudo make install
```

### 7.docker部署与使用
详细看/docker/readme.md

### 8. Request and Push
