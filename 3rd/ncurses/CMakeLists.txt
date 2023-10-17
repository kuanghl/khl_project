# 指定CMake编译最低要求版本
cmake_minimum_required(VERSION 2.8)

include(FindCurses)

if(CURSES_FOUND)
    # dependent on libncurses5-dev, and libncursesw5-dev.
    message(STATUS "Find the curses or ncurses include file: ${CURSES_INCLUDE_DIRS}")
    message(STATUS "Find the curses or ncurses library: ${CURSES_LIBRARIES}")
    set(CURSES_INCLUDE_DIRS ${CURSES_INCLUDE_DIRS} CACHE INTERNAL "The include directories needed to use Curses.")
    set(CURSES_LIBRARIES ${CURSES_LIBRARIES} CACHE INTERNAL "The libraries needed to use Curses.")
    set(CURSES_FOUND ${CURSES_FOUND} CACHE INTERNAL "True if Curses is found.")
    set(CURSES_CFLAGS ${CURSES_CFLAGS} CACHE INTERNAL "Parameters which ought be given to C/C++ compilers when using Curses.")
    set(CURSES_HAVE_CURSES_H ${CURSES_HAVE_CURSES_H} CACHE INTERNAL "True if curses.h is available.")
endif()