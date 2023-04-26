# 指定CMake编译最低要求版本
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# 寻找线程包环境
FIND_PACKAGE(Threads REQUIRED)

# 设置子目录并构建
# ADD_SUBDIRECTORY(common_pref)

# googlebenchmark编译开关
OPTION(gbenchmark_en "Enable the gbenchmark: on/off" on)
IF(gbenchmark_en STREQUAL "on")
    MESSAGE(STATUS "Config: gbenchmark = on.")
    # # 使能cmake外部项目
    # include(ExternalProject)

    # # 下载安装googletest release版本
    # ExternalProject_Add(
    #     googlebenchmark
    #     #     URL https://github.com/google/benchmark/archive/benchmark-1.7.1.zip
    #     URL ${CMAKE_CURRENT_SOURCE_DIR}/gbenchmark/benchmark-1.7.1.zip
    #     PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gbenchmark 
    # )
    
ELSE()  # lib: benchmark benchmark_main pthread /gtest_main
    MESSAGE(STATUS "Config: gbenchmark = off, we will get clone google benchmark to build.")

    # 设置子目录并构建
    ADD_SUBDIRECTORY(benchmark)

    # 指定暴露gtest头文件
    include_directories(${benchmark_SOURCE_DIR}/include)
ENDIF()
