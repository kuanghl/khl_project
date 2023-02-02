# 指定CMake编译最低要求版本
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# 查询当前目录下的/ /test_x 包含的所有.cpp文件
FILE(GLOB COMMON_TEST_SRCS "test001_x.cpp" "main.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
                           "${CMAKE_CURRENT_SOURCE_DIR}/test_x/*.cpp")

# 生成可执行文件
ADD_EXECUTABLE(common_test ${COMMON_TEST_SRCS})

# 查找当前目录路径下文件及其他路径下的文件,pthread=${CMAKE_THREAD_LIBS_INIT}
IF(gtest_en STREQUAL "on")
    TARGET_LINK_LIBRARIES(common_test libgtest libgmock ${LINK_LIB})
ELSE()
    TARGET_LINK_LIBRARIES(common_test pthread gtest gtest_main gmock gmock_main ${LINK_LIB}) 
ENDIF()

ADD_TEST(NAME common_test
         COMMAND common_test)