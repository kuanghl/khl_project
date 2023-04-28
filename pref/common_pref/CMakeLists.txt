# 指定CMake编译最低要求版本
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# 查询当前目录下的/ /test_x 包含的所有.cpp文件
FILE(GLOB COMMON_PREF_SRCS "pref001_x.cpp" "main.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
                           "${CMAKE_CURRENT_SOURCE_DIR}/pref_x/*.cpp")

# 生成可执行文件
ADD_EXECUTABLE(common_pref ${COMMON_PREF_SRCS})

# 查找当前目录路径下文件及其他路径下的文件,pthread=${CMAKE_THREAD_LIBS_INIT}
IF(gbenchmark_en STREQUAL "on")
    # TARGET_LINK_LIBRARIES(common_pref libbenchmark ${LINK_LIB})
    MESSAGE(STATUS "Config: gbenchmark = on, use ExternalProject(error not configure).")
ELSE()
    TARGET_LINK_LIBRARIES(common_pref benchmark benchmark_main pthread ${LINK_LIB}) 
ENDIF()

INSTALL(TARGETS common_pref DESTINATION ${CMAKE_CURRENT_BINARY_DIR})