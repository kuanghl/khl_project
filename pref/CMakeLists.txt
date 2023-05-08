# 指定CMake编译最低要求版本
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# 寻找线程包环境
FIND_PACKAGE(Threads REQUIRED)

# 设置子目录并构建
ADD_SUBDIRECTORY(common_pref)

set(BENCHMARK_ENABLE_TESTING OFF)

# googlebenchmark编译开关
OPTION(gbenchmark_en "Enable the gbenchmark_en: on/off" on)
IF(gbenchmark_en STREQUAL "on") # lib: benchmark benchmark_main pthread(无编译测试例)
    MESSAGE(STATUS "Config: gbenchmark_en = on, use ExternalProject(error not configure).")

ELSEIF(gbenchmark_en STREQUAL "other") # lib: benchmark benchmark_main pthread(编译测试例)
    MESSAGE(STATUS "Config: gbenchmark_en = other, use FetchContent.")
    # 使能cmake外部项目
    include(FetchContent) 

    # 下载安装benchmark release版本
    fetchcontent_declare(
        googlebenchmark
        #     URL https://github.com/google/benchmark/releases/tag/benchmark-1.7.1.zip
        URL ${CMAKE_CURRENT_SOURCE_DIR}/gbenchmark/benchmark-1.7.1.zip
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gbenchmark 
    )
    fetchcontent_makeavailable(googlebenchmark)

    # 指定暴露benchmark头文件
    include_directories(${benchmark_SOURCE_DIR}/include)

ELSE()  # lib: benchmark benchmark_main pthread(编译测试例)
    MESSAGE(STATUS "Config: gbenchmark_en = off, we will get clone google benchmark to build.")

    # 设置子目录并构建
    ADD_SUBDIRECTORY(benchmark)

    # 指定暴露benchmark头文件
    include_directories(${benchmark_SOURCE_DIR}/include)
ENDIF()
