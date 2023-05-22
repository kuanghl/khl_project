cmake_minimum_required(VERSION 3.10)

project(CppProjectSample LANGUAGES CXX)

# Library
add_library(
    SampleLib
    lib/include/simple_calc.hpp
    lib/include/i_warper.hpp
    lib/include/basic_warper.hpp
    lib/include/checked_warper.hpp
    lib/include/clamped_warper.hpp
    lib/include/operation_strategy.hpp
    lib/src/basic_warper.cpp
    lib/src/checked_warper.cpp
    lib/src/clamped_warper.cpp
    lib/src/operation_strategy.cpp
)

set_target_properties(
    SampleLib
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
        LINKER_LANGUAGE CXX
        SOVERSION 1
        VERSION 1.0.0
)

target_compile_options(
    SampleLib
    PRIVATE
         $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
         $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic>
)

target_include_directories(
    SampleLib
    PUBLIC
        lib/include
)

# Sample App
add_executable(
    SampleLibApp
    app/main.cpp
)

set_target_properties(
    SampleLibApp
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

target_compile_options(
    SampleLibApp
    PRIVATE
         $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
         $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)

target_link_libraries(
    SampleLibApp
    PRIVATE
        SampleLib
)

# Test of Library
include(CTest)

add_executable(
    TestSampleLib
    test/test_simple_calc.cpp
    test/test_basic_warper.cpp
    test/test_checked_warper.cpp
    test/test_clamped_warper.cpp
    test/test_mocked_warper.cpp
    test/test_operation_strategy.cpp
    test/test_operation_strategy_logic.cpp
    test/test_operation_strategy_edge.cpp
    test/main.cpp
)

set_target_properties(
    TestSampleLib
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

target_include_directories(
    TestSampleLib
    PRIVATE
        .
)

target_link_libraries(
    TestSampleLib
    PRIVATE
        SampleLib
)

add_test(NAME TestSampleLib COMMAND TestSampleLib)

# Test coverage
find_program(GCOV_PATH gcov)
if (NOT GCOV_PATH)
    message(WARNING "program gcov not found")
endif()

find_program(LCOV_PATH lcov)
if (NOT LCOV_PATH)
    message(WARNING "program lcov not found")
endif()

find_program(GENHTML_PATH genhtml)
if (NOT GENHTML_PATH)
    message(WARNING "program genhtml not found")
endif()

if (LCOV_PATH AND GCOV_PATH)

    target_compile_options(
        SampleLib
        PRIVATE
            -g -O0 -fprofile-arcs -ftest-coverage
    )

    target_link_libraries(
        SampleLib
        PRIVATE
            --coverage
    )

    set(covname cov)

    add_custom_target(cov_data
        # Cleanup lcov
        ${LCOV_PATH} --directory . --zerocounters

        # Run tests
        COMMAND TestSampleLib

        # Capturing lcov counters and generating report
        COMMAND ${LCOV_PATH} --directory . --capture --output-file ${covname}.info
        COMMAND ${LCOV_PATH} --remove ${covname}.info
                             '${CMAKE_SOURCE_DIR}/lib/include/*'
                             '${CMAKE_SOURCE_DIR}/test/*'
                             '${CMAKE_SOURCE_DIR}/catch2/*'
                             '${CMAKE_SOURCE_DIR}/fakeit/*'
                             '/usr/*'
                             --output-file ${covname}.info.cleaned
    )

    if (GENHTML_PATH)
        add_custom_target(cov
            # Cleanup lcov
            ${LCOV_PATH} --directory . --zerocounters

            # Run tests
            COMMAND TestSampleLib

            # Capturing lcov counters and generating report
            COMMAND ${LCOV_PATH} --directory . --capture --output-file ${covname}.info
            COMMAND ${LCOV_PATH} --remove ${covname}.info
                                 '${CMAKE_SOURCE_DIR}/lib/include/*'
                                 '${CMAKE_SOURCE_DIR}/test/*'
                                 '${CMAKE_SOURCE_DIR}/catch2/*'
                                 '${CMAKE_SOURCE_DIR}/fakeit/*'
                                 '/usr/*'
                                 --output-file ${covname}.info.cleaned
            COMMAND ${GENHTML_PATH} -o ${covname} ${covname}.info.cleaned
            COMMAND ${CMAKE_COMMAND} -E remove ${covname}.info ${covname}.info.cleaned

            COMMENT "Resetting code coverage counters to zero.\nProcessing code coverage counters and generating report."
        )
    else()
        message(WARNING "unable to generate coverage report: missing genhtml")
    endif()

else()
    message(WARNING "unable to add coverage targets: missing coverage tools")
endif()

# To be used with memcheck.yml
find_program(VALGRIND valgrind)
if(VALGRIND)
    add_custom_target(valgrind
        COMMAND "${VALGRIND}" --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=40 --track-origins=yes --track-fds=yes --log-file=memcheck.txt $<TARGET_FILE:TestSampleLib>)
else()
    add_custom_target(valgrind COMMENT "Valgrind not found")
endif()


# Package generation
install(
    TARGETS
       SampleLib
       SampleLibApp
       TestSampleLib
    DESTINATION 
       sample_lib
)

set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PACKAGE_DESCRIPTION "Minimal C++ test example")
set(CPACK_GENERATOR "DEB") # Debian package
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON) # autogenerate dependency information
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Code Author") # mandatory

include(CPack)
