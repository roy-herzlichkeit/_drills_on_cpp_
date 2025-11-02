cmake_minimum_required(VERSION 3.14.0)
project(testsome)

# Find the installed library
# CMake will search in standard system paths automatically
find_library(ADDER_HZLCM_LIB adder_HZLCM)
find_path(ADDER_HZLCM_INCLUDE adder.h)

# Check if found
if(NOT ADDER_HZLCM_LIB)
    message(FATAL_ERROR "adder_HZLCM library not found!")
endif()
if(NOT ADDER_HZLCM_INCLUDE)
    message(FATAL_ERROR "adder.h header not found!")
endif()

add_executable(testsome main.cpp)
target_include_directories(testsome PRIVATE ${ADDER_HZLCM_INCLUDE})
target_link_libraries(testsome ${ADDER_HZLCM_LIB})