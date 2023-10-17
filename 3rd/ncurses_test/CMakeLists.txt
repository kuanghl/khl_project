# 指定CMake编译最低要求版本
cmake_minimum_required(VERSION 2.8)

# 生成可执行文件
add_executable(ncurses_test "${CMAKE_CURRENT_SOURCE_DIR}/main.c")

# 链接库
target_include_directories(ncurses_test PUBLIC ${CURSES_INCLUDE_DIR})
target_link_libraries(ncurses_test ${CURSES_LIBRARIES})