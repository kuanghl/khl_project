# 指定CMake编译最低要求版本
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# 设置变量TARGET=server
SET(TARGET codetest)

# 指定头文件路径在当前目录下的/crc /
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/crc)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/)

# 查询当前目录下的/ /hh /mm /ll 包含的所有.c文件
FILE(GLOB SERVER_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/crc/*.c")

# 指定头文件路径为项目根目录/log/simple_log
# 追加SERVER_SRCS变量内容log.c
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/log/simple_log)
SET(CODETEST_SRCS ${CODETEST_SRCS} ${PROJECT_SOURCE_DIR}/log/simple_log/log.c)

# 判断系统处理器类型
IF(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "x86_amd64")
	message(STATUS "x86_64 architecture detected")
ELSEIF(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "AMD64")
	message(STATUS "x64 architecture detected")
ELSE()
    message(STATUS "x32 x64 or x86 isn't detected")
ENDIF()

# 生成可执行文件
ADD_EXECUTABLE(${TARGET} ${CODETEST_SRCS})

# 链接到库
TARGET_LINK_LIBRARIES(${TARGET} ${LINK_LIB})

# 安装目标文件TARGET为可执行二进制文件(RUNTIME)到/bin路径下
install (TARGETS ${TARGET}
    RUNTIME
    DESTINATION ${CMAKE_INSTALL_BINDIR})
