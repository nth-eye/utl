cmake_minimum_required(VERSION 3.0.0)
project(util VERSION 0.1.0)

add_library(libutl INTERFACE)
target_compile_features(libutl INTERFACE cxx_std_11)
target_compile_options(libutl INTERFACE "-Wall" "-Wextra" "-Wpedantic")
target_include_directories(libutl INTERFACE inc)

add_executable(utl main.cpp)
target_compile_features(utl PUBLIC cxx_std_11)
target_link_libraries(utl PUBLIC libutl)

add_executable(utltest test/test_utl.cpp)
target_compile_features(utltest PUBLIC cxx_std_11)
target_link_libraries(utltest PUBLIC gtest_main libutl)

enable_testing()
include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)
gtest_discover_tests(utltest)