# 指定CMake编译最低要求版本
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# 设置子目录并构建
ADD_SUBDIRECTORY(runtime_api)

# 指定头文件路径位于项目根目录下/include
FILE(GLOB client_inc "${PROJECT_SOURCE_DIR}/include/*.h")

# 查询当前目录下的/drv_api包含的所有.c文件
FILE(GLOB drv_api  
    "${CMAKE_CURRENT_SOURCE_DIR}/drv_api/*.c")

# 指定暴露头文件
INCLUDE_DIRECTORIES(runtime_api_include ${CMAKE_CURRENT_BINARY_DIR})

# 查询当前目录下的/runtime_api /runtime_api/flexbison包含的所有.c文件
FILE(GLOB runtime_api 
    "${CMAKE_CURRENT_SOURCE_DIR}/runtime_api/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/runtime_api/flexbison/*.cpp")

# 设置追加其他库变量,线程包
FIND_PACKAGE(Threads)
SET(runtime_api_lib dl boost_system boost_filesystem boost_thread pthread)

# 生成动态库,链接到库
ADD_LIBRARY(client_api SHARED ${drv_api} ${runtime_api})
TARGET_LINK_LIBRARIES(client_api ${LINK_LIB} ${runtime_api_lib})

# 链接到库flexbison
# target_link_libraries(client_api parser)


# 安装目标文件TARGET为可执行二进制文件(RUNTIME)到/bin路径下
install(FILES ${client_inc} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(TARGETS client_api LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
