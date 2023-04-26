# 指定CMake编译最低要求版本
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# 判断系统处理器类型
IF(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "x86_amd64")
	message(STATUS "x86_64 architecture detected")
ELSEIF(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "AMD64")
	message(STATUS "x64 architecture detected")
ELSE()
    message(STATUS "x32 x64 or x86 isn't detected")
ENDIF()

# 默认构建类型设置为Release 用法：cmake .. -DCMAKE_BUILD_TYPE=Release
if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
	message(STATUS "Setting build type to 'Release' as none was specified.")
	set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
	# Set the possible values of build type for cmake-gui
	set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
		"MinSizeRel" "RelWithDebInfo")
endif ()

# # 编译选项设置
SET(CMAKE_C_FLAGS_RELEASE "-D_REETRANT -DNDEBUG -fPIC -Wall -Wextra -pedantic -O3 -std=gnu99 -v")
SET(CMAKE_C_FLAGS_DEBUG "-D_REETRANT -g -fPIC -Wall -Wextra -pedantic -O0 -v")
SET(CMAKE_CXX_FLAGS_RELEASE "-Wall -O2")
SET(CMAKE_CXX_FLAGS_DEBUG "-g")

# 给项目命名,解决CMP0048
IF(CMAKE_VERSION VERSION_LESS 3.0)
  PROJECT(khl_project)
  SET(PROJECT_VERSION 0)
ELSE()
  CMAKE_POLICY(SET CMP0048 NEW)
  PROJECT(khl_project)
ENDIF()

# 设置工程版本号
SET(${PROJECT_NAME}_VERSION 0)
SET(${PROJECT_NAME}_SOVERSION 0)
SET(${PROJECT_NAME}_VERSION_MAJOR 0)
SET(${PROJECT_NAME}_VERSION_MINOR 0)

# 指定头文件目录
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

# 编译条件设置,让程序按照cmake设置编译条件编译
# case 0
OPTION(mps_en "Enable the mps: on/off" on)
IF(mps_en STREQUAL "off")
	MESSAGE(STATUS "Config: mps_en=off.")
	ADD_DEFINITIONS("-Dmps_en=0")
ELSE()
	MESSAGE(STATUS "Config: mps_en=on.")
	ADD_DEFINITIONS("-Dmps_en=1")
ENDIF()
# case 1
OPTION(daemon_en "Enable the daemon: on/off" on)
IF(daemon_en STREQUAL "off")
	MESSAGE(STATUS "Config: daemon_en=off.")
	ADD_DEFINITIONS("-Ddaemon_en=0")
ELSE()
	MESSAGE(STATUS "Config: daemon_en = on.")
	ADD_DEFINITIONS("-Ddaemon_en=1")
ENDIF()
# case 2 log
OPTION(loglevel "set the log level(0-fatal, 1-error, 2-warn, 3-info, 4-debug, 5-trace, default 3)" 3)
IF(loglevel STREQUAL "OFF")
    MESSAGE(STATUS "Config warning: loglevel isn't set, default loglevel is 3.")
ELSE()
	MESSAGE(STATUS "Config: loglevel = ${loglevel}.")
	ADD_DEFINITIONS("-Dloglevel=${loglevel}")
ENDIF()
# case 3 log
OPTION(logcolor_en "Enable the log color to use: on/off" off)
IF(logcolor_en STREQUAL "off")
	MESSAGE(STATUS "Config: logcolor_en = off.")
	ADD_DEFINITIONS("-Dlogcolor_en=0")
ELSE()
	MESSAGE(STATUS "Config: logcolor_en = on.")
	ADD_DEFINITIONS("-Dlogcolor_en=1")
ENDIF()

# 设置子目录并构建，追加变量LINK_LIB变量为simple_log PUBLIC动态库log,指定头文件地址暴露
ADD_SUBDIRECTORY(log)
SET(LINK_LIB ${LINK_LIB} log)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/log/simple_log)

# 追加LINK_LIB变量为gcc_s,设置子目录并构建,追加LINK_LIB变量为libuv PUBLIC静态库uv_a,指定头文件地址进行暴露
SET(LINK_LIB ${LINK_LIB} gcc_s)
ADD_SUBDIRECTORY(3rd)
SET(LINK_LIB ${LINK_LIB} uv_a)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/3rd/libuv/include)

# googletest,设置子目录并构建
# enable_testing()
ADD_SUBDIRECTORY(test)

# googlebenchmark,设置子目录并构建
ADD_SUBDIRECTORY(pref)

# 设置可执行二进制文件输出位置
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/funbin/)

# 设置子目录并构建
ADD_SUBDIRECTORY(fun)

# 设置可执行二进制文件输出位置
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/cfunbin/)

# 设置子目录并构建
ADD_SUBDIRECTORY(cfun)

# 设置可执行二进制文件输出位置
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin/)

# 设置子目录并构建
ADD_SUBDIRECTORY(lib)
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(tools)


