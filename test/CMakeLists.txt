# 指定CMake编译最低要求版本
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# 寻找线程包环境
FIND_PACKAGE(Threads REQUIRED)

# 设置子目录并构建
ADD_SUBDIRECTORY(common_test)

# 允许测试例运行
# enable_testing()

OPTION(gtest_en "Enable the gtest: on/off" on)
IF(gtest_en STREQUAL "on") # lib: libgtest libgmock
    MESSAGE(STATUS "Config: gtest_en = on, use ExternalProject.")
    # 使能cmake外部项目
    include(ExternalProject)

    # 下载安装googletest release版本
    ExternalProject_Add(
        gtest
        #     URL https://github.com/google/googletest/archive/release-1.12.1.zip
        URL ${CMAKE_CURRENT_SOURCE_DIR}/gtest/release-1.12.1.zip
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
        # Disable install step
        INSTALL_COMMAND ""
        TIMEOUT 60
        GIT_PROGRESS true
    )

    # 从cmake外部项目中获取源文件地址和二进制文件地址
    ExternalProject_Get_Property(gtest SOURCE_DIR BINARY_DIR)

    # 构建libgtest静态库 IMPORTED外部引用库转为内部使用 GLOBAL全局可见
    # 设置库路径及选项,CMAKE_THREAD_LIBS_INIT=链接线程库
    add_library(libgtest IMPORTED STATIC GLOBAL)
    add_dependencies(libgtest gtest)
    set_target_properties(libgtest PROPERTIES
        "IMPORTED_LOCATION" "${binary_dir}/lib/libgtest.a"
        "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
    )

    # 构建libgmock静态库 IMPORTED外部引用库转为内部使用 GLOBAL全局可见
    # 设置库路径及选项
    add_library(libgmock IMPORTED STATIC GLOBAL)
    add_dependencies(libgmock gtest)
    set_target_properties(libgmock PROPERTIES
        "IMPORTED_LOCATION" "${binary_dir}/lib/libgmock.a"
        "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
    )

    # 指定暴露gtest头文件
    include_directories("${SOURCE_DIR}/googletest/include"
                        "${SOURCE_DIR}/googlemock/include") 

ElSEIF(gtest_en STREQUAL "other") # lib: pthread gtest gtest_main gmock gmock_main
    MESSAGE(STATUS "Config: gtest_en = other, use FetchContent.")
    # 使能cmake外部项目
    include(FetchContent) 

    # 下载安装googletest release版本
    fetchcontent_declare(
        gtest
        #     URL https://github.com/google/googletest/archive/release-1.12.1.zip
        URL ${CMAKE_CURRENT_SOURCE_DIR}/gtest/release-1.12.1.zip
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
    )
    fetchcontent_makeavailable(gtest)

    # 指定暴露gtest头文件
    include_directories(${gtest_SOURCE_DIR}/include)
    include_directories(${gmock_SOURCE_DIR}/include)

ELSE()  # lib: pthread gtest gtest_main gmock gmock_main
    MESSAGE(STATUS "Config: gtest_en = off, we will get clone googletest to build.")

    # 设置子目录并构建
    add_subdirectory(googletest)
    
    # 指定暴露gtest头文件
    include_directories(${gtest_SOURCE_DIR}/include)
    include_directories(${gmock_SOURCE_DIR}/include)
ENDIF()

