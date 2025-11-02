cmake_minimum_required(VERSION 3.14)
project(herzlich)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(glfw3 CONFIG REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

find_library(ADDER_HRZ_LIB 
    NAMES adder_hrz
    PATHS "C:/Program Files (x86)/adder_hrz/lib"
    NO_DEFAULT_PATH
)
find_path(ADDER_HRZ_INCLUDE 
    NAMES adder.h
    PATHS "C:/Program Files (x86)/adder_hrz/include"
    NO_DEFAULT_PATH
)

if(NOT ADDER_HRZ_LIB)
    message(FATAL_ERROR "adder_hrz library not found!")
endif()
if(NOT ADDER_HRZ_INCLUDE)
    message(FATAL_ERROR "adder.h header not found!")
endif()

target_include_directories(${PROJECT_NAME} 
    PRIVATE ${ADDER_HRZ_INCLUDE}
)

target_link_libraries(${PROJECT_NAME} 
    PRIVATE ${ADDER_HRZ_LIB}
    PRIVATE glfw
)