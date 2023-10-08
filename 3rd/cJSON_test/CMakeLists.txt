# 指定CMake编译最低要求版本
cmake_minimum_required(VERSION 2.8)

# 暴露头文件
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../cJSON/)

# 生成可执行文件
add_executable(json_test ${CMAKE_CURRENT_SOURCE_DIR}/json_test.c)
add_executable(test ${CMAKE_CURRENT_SOURCE_DIR}/test.c)
target_link_libraries(json_test cjson)
target_link_libraries(test cjson)

