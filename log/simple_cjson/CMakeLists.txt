# 指定CMake编译最低要求版本
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# 暴露头文件
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/)

# 设置LIBLOG_SRC变量
FILE(GLOB LIBJSON_SRC "${CMAKE_CURRENT_SOURCE_DIR}/cJSON.c") 

# 取变量LIBJSON_SRC值，指定生成动态库libjson.so
ADD_LIBRARY(json SHARED 
    ${LIBJSON_SRC}
)

# 为动态库libjson.so指定头文件目录为当前目录CMAKE_CURRENT_SOURCE_DIR
target_include_directories(json PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# 将头文件安装到CMAKE_INSTALL_INCLUDEDIR目录下
# 将库安装到CMAKE_INSTALL_LIBDIR目录下
install(TARGETS json LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})