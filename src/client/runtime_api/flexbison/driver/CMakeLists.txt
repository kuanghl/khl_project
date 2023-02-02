find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

BISON_TARGET(parser parser.yy ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
FLEX_TARGET(lexer lexer.ll ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp)
ADD_FLEX_BISON_DEPENDENCY(lexer parser)

add_library(flexbisonlib SHARED driver.cpp
        ${FLEX_lexer_OUTPUTS}
        ${BISON_parser_OUTPUTS}
        )

target_include_directories(flexbisonlib PRIVATE . ${CMAKE_CURRENT_BINARY_DIR})
# set_property(TARGET flexbisonlib PROPERTY CXX_STANDARD 11)