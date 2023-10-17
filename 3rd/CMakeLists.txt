# 指定CMake编译最低要求版本
cmake_minimum_required(VERSION 2.8)

# 构建类型设置为
# set(CMAKE_BUILD_TYPE "Debug")

#############################################################
# libuv编译项
option(libuv_en "Enable the libuv_en: on/off/other" on)
if(libuv_en STREQUAL "on") # lib: uv_a(无编译测试例)
    message(STATUS "Config: libuv_en = on, use ExternalProject(error not configure).")

elseif(libuv_en STREQUAL "other") # lib: uv_a(编译测试例)
    message(STATUS "Config: libuv_en = other, use FetchContent.")
    # 使能cmake外部项目
    include(FetchContent) 

    # 下载安装libuv release版本
    fetchcontent_declare(
        libuv
        #     URL https://github.com/libuv/libuv/releases/libuv-1.45.0.zip
        URL ${CMAKE_CURRENT_SOURCE_DIR}/llibuv/libuv-1.45.0.zip
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/llibuv
    )
    fetchcontent_makeavailable(libuv)

    # 指定暴露libuv头文件
    include_directories(${libuv_SOURCE_DIR}/include)

else()  # lib: uv_a(编译测试例)
    message(STATUS "Config: libuv_en = off, we will get clone libuv to build.")

    # 设置子目录并构建
    add_subdirectory(libuv)

    # 设置libuv项目源路径
    set(libuv_SOURCE_DIR "${CMAKE_CURRENT_BINARY_DIR}/libuv")


    # 指定暴露libuv头文件
    include_directories(${libuv_SOURCE_DIR}/include)

endif()

# libuv_test

#############################################################
# cJSON
# 设置子目录并构建
add_subdirectory(cJSON)
# cJSON_test
add_subdirectory(cJSON_test)

#############################################################
# pybind11
# 设置子目录并构建
add_subdirectory(pybind11)
# pybind11_test
add_subdirectory(pybind11_test)

#############################################################
# ncurses
add_subdirectory(ncurses)

# ncurses_test
add_subdirectory(ncurses_test)

