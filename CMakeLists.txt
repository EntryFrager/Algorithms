cmake_minimum_required(VERSION 3.20)
project(algo CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(gtest URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip)
FetchContent_MakeAvailable(gtest)

enable_testing()
include(GoogleTest)

file(GLOB_RECURSE SRCS CONFIGURE_DEPENDS codeforces/*.cpp cses/*.cpp)

foreach( file ${SRCS} )
    file(RELATIVE_PATH rel ${CMAKE_SOURCE_DIR} ${file})
    string(REGEX REPLACE "[/.]" "_" target ${rel})

    add_executable(${target} ${file})
    target_compile_definitions(${target} PRIVATE LOCAL_TESTS)
    target_link_libraries(${target} PRIVATE GTest::gtest_main)
    gtest_discover_tests(${target})
endforeach()