- [Demo study environment.](#demo-study-environment)
  - [1. 3rd develop](#1-3rd-develop)
  - [2. gtest](#2-gtest)
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

### 2. gtest
google test单元测试平台搭建及使用。

### 3. linux c
linux 相关库函数及POSIX标准函数使用及积累。

### 4. network
网络相关的内容学习及运用。

### 5. data struct
数据结构及算法通用库构建。

### 6. 编译及使用方法
cmake整项目编译指令流程：
```
cmake .. -Dloglevel=5
make -j16
sudo make install
```

### 7. Request and Push.
