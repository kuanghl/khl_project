# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# project(flex_bison_cmake CXX)

cmake_minimum_required(VERSION 2.8)

include_directories(include)
add_subdirectory(driver)

add_executable(flexbison_main main.cpp)
target_link_libraries(flexbison_main flexbisonlib)
# set_property(TARGET flexbison_main PROPERTY CXX_STANDARD 11)

set_target_properties(flexbison_main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ".")
