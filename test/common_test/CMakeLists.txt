# 指定CMake编译最低要求版本
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# 查找当前目录路径下文件及其他路径下的文件
IF(gtest_en STREQUAL "on")
    # TARGET_LINK_LIBRARIES(common_test libgtest libgmock)
ELSE()
    # TARGET_LINK_LIBRARIES(common_test pthread gtest gtest_main)
ENDIF()