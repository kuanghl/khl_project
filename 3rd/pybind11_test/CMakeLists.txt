# 指定CMake编译最低要求版本
cmake_minimum_required(VERSION 2.8)

# header and src
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../pybind11/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
file(GLOB_RECURSE TEST_PYTHON_API_SOURCES    "${CMAKE_CURRENT_SOURCE_DIR}/pytest.cpp")

# link
pybind11_add_module(pytest ${TEST_PYTHON_API_SOURCES})
# target_link_libraries(pytest PUBLIC urpp)

# copy pytest.py
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/pytest.py DESTINATION ${PROJECT_BINARY_DIR}/3rd/pybind11_test)
