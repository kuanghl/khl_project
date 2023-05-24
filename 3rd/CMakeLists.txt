# 指定CMake编译最低要求版本
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# 构建类型设置为
# SET(CMAKE_BUILD_TYPE "Debug")

# libuv编译项
OPTION(libuv_en "Enable the libuv_en: on/off/other" on)
IF(libuv_en STREQUAL "on") # lib: uv_a(无编译测试例)
    MESSAGE(STATUS "Config: libuv_en = on, use ExternalProject(error not configure).")

ELSEIF(libuv_en STREQUAL "other") # lib: uv_a(编译测试例)
    MESSAGE(STATUS "Config: libuv_en = other, use FetchContent.")
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

ELSE()  # lib: uv_a(编译测试例)
    MESSAGE(STATUS "Config: libuv_en = off, we will get clone libuv to build.")

    # 设置子目录并构建
    ADD_SUBDIRECTORY(libuv)

    # 设置libuv项目源路径
    set(libuv_SOURCE_DIR "${CMAKE_CURRENT_BINARY_DIR}/libuv")


    # 指定暴露libuv头文件
    include_directories(${libuv_SOURCE_DIR}/include)

ENDIF()