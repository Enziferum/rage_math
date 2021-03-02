cmake_minimum_required(VERSION 3.17)
project(rage_math)

option(BUILD_TESTS "Build tests of math ?" ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if(CMAKE_BUILD_TYPE MATCHES DEBUG)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()


file(GLOB SRC src/*.cpp)
include_directories(${CMAKE_SOURCE_DIR}/incl)

add_library(${PROJECT_NAME} ${SRC})
target_include_directories(${PROJECT_NAME}
        PUBLIC ${CMAKE_SOURCE_DIR}/incl)

if(BUILD_TESTS)
    include(cmake/External_GTest.cmake)
    enable_testing()

    set(TESTS_NAME run_all_tests)
    #target_compile_options(rage_math PRIVATE -fprofile-arcs -ftest-coverage -O0 -pg -g)


    include_directories(.)
    include_directories(${GTEST_INCLUDE_DIRS})
    set(SRC
            tests/runner.cpp
            tests/test_math.cpp
            tests/test_matrix.cpp
            tests/test_vec2.cpp
            tests/test_vec3.cpp
            )

    add_executable(${TESTS_NAME} ${SRC})
    target_link_libraries(${TESTS_NAME}  gtest rage_math)
    #target_compile_options(${TESTS_NAME} PRIVATE -fprofile-arcs -ftest-coverage -O0 -g -pg)
    add_dependencies(${TESTS_NAME} gtest_ext)
    #target_compile_options(gtest PRIVATE -fprofile-arcs -ftest-coverage -O0 -pg -g)
    add_test(NAME unit_tests COMMAND ${TESTS_NAME})
endif()