# 指定CMake编译最低要求版本
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# 编译条件设置,让程序按照cmake设置编译条件编译
# 这部分配置放置在项目根目录CMakeLists.txt下全局生效，否则引用log.h文件中的预编译无法获取loglevel
# 而log.c文件中的logcolor_en因为已编译成库不受影响
# case 0
# OPTION(loglevel "set the log level(0-fatal, 1-error, 2-warn, 3-info, 4-debug, 5-trace, default 3)" 3)
# IF(loglevel STREQUAL "OFF")
#     MESSAGE(STATUS "Config warning: loglevel isn't set.")
# ELSE()
# 	MESSAGE(STATUS "Config: loglevel=${loglevel}")
# 	ADD_DEFINITIONS("-Dloglevel=${loglevel}")
# ENDIF()
# case 1
# OPTION(logcolor_en "Enable the log color to use: on/off" off)
# IF(logcolor_en STREQUAL "off")
# 	MESSAGE(STATUS "Config: logcolor_en=off")
# 	ADD_DEFINITIONS("-Dlogcolor_en=0")
# ELSE()
# 	MESSAGE(STATUS "Config: logcolor_en=on")
# 	ADD_DEFINITIONS("-Dlogcolor_en=1")
# ENDIF()

# 指定头文件
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

# 设置LIBLOG_SRC变量
SET(LIBLOG_SRC
    log.h
    log.c
)

# 取变量LIBLOG_SRC值，指定生成动态库liblog.so
ADD_LIBRARY(log SHARED 
    ${LIBLOG_SRC}
)

# 为动态库liblog.so指定头文件目录为当前目录CMAKE_CURRENT_SOURCE_DIR
target_include_directories(log PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# 设置log动态库版本VERSION=${${PROJECT_NAME}_VERSION}
# 设置api版本SOVERSION=${${PROJECT_NAME}_SOVERSION
SET_TARGET_PROPERTIES(log PROPERTIES VERSION ${${PROJECT_NAME}_1.0} SOVERSION ${${PROJECT_NAME}_1.0})

# 将头文件安装到CMAKE_INSTALL_INCLUDEDIR目录下
# 将库安装到CMAKE_INSTALL_LIBDIR目录下
install(FILES log.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(TARGETS log LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
