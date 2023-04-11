[TOC]

## Demo study environment.
嵌入式C/C++多平台开发学习平台，可以用于开发前测试及积累。综合多种高效库及架构，适用于个人学习及移植使用。

### 3rd develop
三方库引用x86/Risv平台，Linux环境下开发。
- libuv
- liteos-a

### gtest
google test单元测试平台搭建及使用。

### linux c
linux 相关库函数及POSIX标准函数使用及积累。

### network
网络相关的内容学习及运用。

### data struct
数据结构及算法通用库构建。

### 编译及使用方法
cmake整项目编译指令流程：
```
cmake .. -Dloglevel=5
make -j16
sudo make install
```

### Request and Push.
