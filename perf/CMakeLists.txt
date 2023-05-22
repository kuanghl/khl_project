# 指定CMake编译最低要求版本
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# 寻找线程包环境
FIND_PACKAGE(Threads REQUIRED)

# 设置子目录并构建
ADD_SUBDIRECTORY(common_perf)

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
        #     URL https://github.com/google/benchmark/releases/tag/benchmark-1.8.0.zip
        URL ${CMAKE_CURRENT_SOURCE_DIR}/bbenchmark/benchmark-1.8.0.zip
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/bbenchmark 
    )
    fetchcontent_makeavailable(googlebenchmark)

    # 指定暴露benchmark头文件
    include_directories(${googlebenchmark_SOURCE_DIR}/include)

ELSE()  # lib: benchmark benchmark_main pthread(编译测试例)
    MESSAGE(STATUS "Config: gbenchmark_en = off, we will get clone google benchmark to build.")

    # 设置子目录并构建
    ADD_SUBDIRECTORY(benchmark)

    # 设置benchmark项目源路径
    set(benchmark_SOURCE_DIR "${CMAKE_CURRENT_BINARY_DIR}/benchmark")

    # 指定暴露benchmark头文件
    include_directories(${benchmark_SOURCE_DIR}/include)
ENDIF()


# google gperftools编译开关
OPTION(gperftools_en "Enable the gperftools_en: on/off" on)
IF(gperftools_en STREQUAL "on") # lib: profiler tcmalloc unwind pthread(无编译测试例)
    MESSAGE(STATUS "Config: gperftools_en = on, use ExternalProject(error not configure).")

ELSEIF(gperftools_en STREQUAL "other") # lib: profiler tcmalloc unwind pthread(编译测试例)
    MESSAGE(STATUS "Config: gperftools_en = other, use FetchContent.")
    # 使能cmake外部项目
    include(FetchContent) 

    # gperftools cmake bug.
    set(HAVE_LIBUNWIND_H "/usr/lib/x86_64-linux-gnu/libunwind.h") 

    # 下载安装gperftools release版本
    fetchcontent_declare(
        gperftools
        #     URL https://github.com/gperftools/gperftools/releases/gperftools-2.10.zip
        URL ${CMAKE_CURRENT_SOURCE_DIR}/ggperftools/gperftools-2.10.zip
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/ggperftools 
    )
    fetchcontent_makeavailable(gperftools)

    # 指定暴露gperftools头文件
    include_directories(${gperftools_SOURCE_DIR}/include)

ELSE()  # lib: profiler tcmalloc unwind pthread(编译测试例)
    MESSAGE(STATUS "Config: gperftools_en = off, we will get clone google gperftools to build.")

    # gperftools cmake bug.
    set(HAVE_LIBUNWIND_H "/usr/lib/x86_64-linux-gnu/libunwind.h") 
    # 设置子目录并构建
    ADD_SUBDIRECTORY(gperftools)

    # 设置benchmark项目源路径
    set(gperftools_SOURCE_DIR "${CMAKE_CURRENT_BINARY_DIR}/gperftools")


    # 指定暴露benchmark头文件
    include_directories(${gperftools_SOURCE_DIR}/include)

ENDIF()


# nanobench编译开关
OPTION(nanobench_en "Enable the nanobench_en: on/off" on)
IF(nanobench_en STREQUAL "on") # lib: nanobench pthread(无编译测试例)
    MESSAGE(STATUS "Config: nanobench_en = on, use ExternalProject(error not configure).")

ELSEIF(nanobench_en STREQUAL "other") # lib: nanobench pthread(编译测试例)
    MESSAGE(STATUS "Config: nanobench_en = other, use FetchContent.")
    # 使能cmake外部项目
    include(FetchContent) 

    # 下载安装nanobench release版本
    fetchcontent_declare(
        nanobench
        #     URL https://github.com/martinus/nanobench/releases/tag/nanobench-4.3.11.zip
        URL ${CMAKE_CURRENT_SOURCE_DIR}/nnanobench/nanobench-4.3.11.zip
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/nnanobench
    )
    fetchcontent_makeavailable(nanobench)

    # 指定暴露nanobench头文件
    include_directories(${nanobench_SOURCE_DIR}/include)

ELSE()  # lib: nanobench pthread(编译测试例)
    MESSAGE(STATUS "Config: nanobench_en = off, we will get clone google nanobench to build.")

    # 设置子目录并构建
    ADD_SUBDIRECTORY(nanobench)

    # 设置benchmark项目源路径
    set(nanobench_SOURCE_DIR "${CMAKE_CURRENT_BINARY_DIR}/nanobench")


    # 指定暴露benchmark头文件
    include_directories(${nanobench_SOURCE_DIR}/include)

ENDIF()


