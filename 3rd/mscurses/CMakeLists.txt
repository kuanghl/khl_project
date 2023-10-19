# 指定CMake编译最低要求版本
cmake_minimum_required(VERSION 2.8)

include(FetchContent) 

# # 编译包
fetchcontent_declare(
    PDCursesMod
    URL ${CMAKE_CURRENT_SOURCE_DIR}/pdcursesmod/PDCursesMod-1.0.3.zip
    GIT_SHALLOW true
    UPDATE_COMMAND ""
    SOURCE_DIR ${CMAKE_CURRENT_BINARY_DIR}/pdcursesmod/
    BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/pdcursesmod/build/
    #sINSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/my_library_install
    INSTALL_COMMAND ""
)
fetchcontent_makeavailable(PDCursesMod)

add_subdirectory(test)