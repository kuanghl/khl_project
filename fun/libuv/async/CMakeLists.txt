# 指定CMake编译最低要求版本
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# # Execute this command, to find your current Linux kernel version.
# execute_process(
#         COMMAND uname -r # This finds your kernel version.
#         OUTPUT_VARIABLE KERNEL_RELEASE # Output the kernel release.
#         OUTPUT_STRIP_TRAILING_WHITESPACE # Add a whitespace.
#         )

# # Now, we want to find the path with all the kernel modules.
# find_path(
#         KERNELHEADERS_DIR # Kernel headers directory.
#         include/linux/user.h # Include this header file.
#         PATHS /usr/src/linux-headers-${KERNEL_RELEASE} # The path of the kernel modules.
#         )
# message(STATUS "Kernel release: ${KERNEL_RELEASE}") # Message to show the kernel release.
# message(STATUS "Kernel headers: ${KERNELHEADERS_DIR}") # Message to show the directory with kernel headers/modules.

# # Include the kernel directories with 'CMake'.
# include_directories(
#         ${KERNELHEADERS_DIR}/include
#         ${CMAKE_CURRENT_SOURCE_DIR}/
#         )

# 包含暴露当前目录下的头文件
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/)

# 设置变量名
SET(TARGET_SRCS libuv_async_srcs)
SET(TARGET_PATH libuv_async_path)
SET(TARGET_NAME libuv_async_name)

# 找到当前目录下的所有.cpp文件存放到TARGET_SRCS
# FILE(GLOB TARGET_SRCS 
#     "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
FILE(GLOB_RECURSE TARGET_SRCS RELATIVE 
    "${CMAKE_CURRENT_SOURCE_DIR}" 
    "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

# 循环取出TARGET_SRCS中的每一个.cpp文件路径存放在TARGET_PATH
foreach(TARGET_PATH IN LISTS TARGET_SRCS)
    # 获取没有路径的文件名储存在TARGET_NAME
    get_filename_component(TARGET_NAME ${TARGET_PATH} NAME_WE)
    # 生成可执行文件
    ADD_EXECUTABLE(${TARGET_NAME} ${TARGET_PATH})
    # 链接到库
    TARGET_LINK_LIBRARIES(${TARGET_NAME} ${LINK_LIB})
    # 安装目标文件TARGET为可执行二进制文件(RUNTIME)到/bin路径下
    install (TARGETS ${TARGET_NAME}
        RUNTIME
        DESTINATION ${CMAKE_INSTALL_BINDIR})
endforeach()