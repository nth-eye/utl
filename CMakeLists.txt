cmake_minimum_required(VERSION 3.0.0)
project(util VERSION 0.1.0)

add_library(utillib INTERFACE)
target_compile_features(utillib INTERFACE cxx_std_11)
target_compile_options(utillib INTERFACE "-Wall" "-Wextra" "-Wpedantic")
target_include_directories(utillib INTERFACE inc)

add_executable(util main.cpp)
target_compile_features(util PUBLIC cxx_std_11)
target_link_libraries(util PUBLIC utillib)

enable_testing()
file(GLOB TEST_FILES test/*.cpp) 

add_executable(utiltest ${TEST_FILES})
target_compile_features(utiltest PUBLIC cxx_std_11)
target_link_libraries(utiltest PUBLIC gtest_main utillib)

include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)
gtest_discover_tests(utiltest)