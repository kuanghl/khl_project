# 指定CMake编译最低要求版本
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# # 查询当前目录下的包含的所有.cpp文件
# FILE(GLOB COMMON_PERF_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/benchmark_test.cpp")

### google benchmark
# 生成可执行文件
ADD_EXECUTABLE(benchmark_test "${CMAKE_CURRENT_SOURCE_DIR}/benchmark_test.cpp")

# 查找当前目录路径下文件及其他路径下的文件,pthread=${CMAKE_THREAD_LIBS_INIT}
IF(benchmark_en STREQUAL "on")
    # TARGET_LINK_LIBRARIES(benchmark_test libbenchmark ${LINK_LIB})
    MESSAGE(STATUS "Config: benchmark_en = on, use ExternalProject(error not configure).")
ELSE()
    TARGET_LINK_LIBRARIES(benchmark_test benchmark benchmark_main pthread ${LINK_LIB}) 
ENDIF()

# INSTALL(TARGETS benchmark_test DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

### gperftools 
# 生成可执行文件
ADD_EXECUTABLE(gperftools_test "${CMAKE_CURRENT_SOURCE_DIR}/gperftools_test.cpp")

# 查找当前目录路径下文件及其他路径下的文件,pthread=${CMAKE_THREAD_LIBS_INIT}
IF(gperftools_en STREQUAL "on")
    MESSAGE(STATUS "Config: gperftools_en = on, use ExternalProject(error not configure).")
ELSE()
    TARGET_LINK_LIBRARIES(gperftools_test profiler unwind pthread ${LINK_LIB}) 
ENDIF()


### nanobench 
# 生成可执行文件
ADD_EXECUTABLE(nanobench_test "${CMAKE_CURRENT_SOURCE_DIR}/nanobench_test.cpp")

# 查找当前目录路径下文件及其他路径下的文件,pthread=${CMAKE_THREAD_LIBS_INIT}
IF(nanobench_en STREQUAL "on")
    MESSAGE(STATUS "Config: nanobench_en = on, use ExternalProject(error not configure).")
ELSE()
    TARGET_LINK_LIBRARIES(nanobench_test nanobench pthread ${LINK_LIB}) 
ENDIF()