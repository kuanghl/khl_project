# 指定CMake编译最低要求版本
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# 设置子目录并构建
ADD_SUBDIRECTORY(client)
ADD_SUBDIRECTORY(codetest)
ADD_SUBDIRECTORY(kernel)
ADD_SUBDIRECTORY(server)
ADD_SUBDIRECTORY(pti)
ADD_SUBDIRECTORY(daemon)
