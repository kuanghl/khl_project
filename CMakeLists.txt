# 指定CMake编译最低要求版本
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# 给项目命名
PROJECT(khl_project)

# 指定头文件目录
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

# 编译条件设置,让程序按照cmake设置编译条件编译
# case 0
OPTION(mps "Enable the mps: on/off" on)
IF(mps STREQUAL "off")
	MESSAGE(STATUS "Config: mps=off")
	ADD_DEFINITIONS(-Dmps)
ELSE()
	MESSAGE(STATUS "Config: mps=on")
	ADD_DEFINITIONS(-Dmps)
ENDIF()
# case 1
OPTION(daemon "Enable the daemon: on/off" on)
IF(daemon STREQUAL "off")
	MESSAGE(STATUS "Config: daemon=off")
	ADD_DEFINITIONS(-Ddaemon)
ELSE()
	MESSAGE(STATUS "Config: daemon=on")
	ADD_DEFINITIONS(-Ddaemon)
ENDIF()
# case 2
OPTION(loglevel "set the log level(0-fatal, 1-error, 2-warn, 3-info, 4-debug, 5-trace, default 3)" 3)
IF(loglevel)
	MESSAGE(STATUS "Config: loglevel=${loglevel}")
	ADD_DEFINITIONS(-Dloglevel)
ENDIF(loglevel)

# 设置子目录并构建,追加变量uv_a,指定头文件地址
ADD_SUBDIRECTORY(3rd)
SET(LINK_LIB ${LINK_LIB} uv_a)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/3rd/libuv/include)

# 设置子目录并构建
ADD_SUBDIRECTORY(lib)
ADD_SUBDIRECTORY(log)
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(test)
ADD_SUBDIRECTORY(tools)

