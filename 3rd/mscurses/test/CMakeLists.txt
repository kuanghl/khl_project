# 指定CMake编译最低要求版本
cmake_minimum_required(VERSION 2.8)

include(FindCurses)

add_executable(mscurses_test ${CMAKE_CURRENT_SOURCE_DIR}/main.c)

target_include_directories(mscurses_test PUBLIC ${CURSES_INCLUDE_DIR})

target_link_libraries(mscurses_test ${CURSES_LIBRARIES})