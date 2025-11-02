cmake_minimum_required(VERSION 3.13.4)

project(L2)

add_executable(${PROJECT_NAME} main.cpp)

install(TARGETS L2 DESTINATION bin)