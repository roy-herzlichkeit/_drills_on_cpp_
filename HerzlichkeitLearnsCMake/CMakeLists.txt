cmake_minimum_required(VERSION 4.1)
project(herzlich VERSION 1.2)

set(HERZLICH_VERSION_MAJOR ${herzlich_VERSION_MAJOR})
set(HERZLICH_VERSION_MINOR ${herzlich_VERSION_MINOR})

option(USE_ADDER "Use Adder library for addition operations" ON)
option(USE_GLFW "Use GLFW library for window creation" OFF)

configure_file(herzlich_config.h.in herzlich.h)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(USE_GLFW)
    find_package(glfw3 CONFIG REQUIRED)
endif()

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

if(USE_ADDER)
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

    if(ADDER_HRZ_LIB AND ADDER_HRZ_INCLUDE)
        message(STATUS "Adder library found - enabling Adder support")
        target_compile_definitions(${PROJECT_NAME} PRIVATE USE_ADDER)
        target_include_directories(${PROJECT_NAME} PRIVATE ${ADDER_HRZ_INCLUDE})
        target_link_libraries(${PROJECT_NAME} PRIVATE ${ADDER_HRZ_LIB})
    else()
        message(WARNING "Adder library not found - disabling Adder support")
        set(USE_ADDER OFF CACHE BOOL "Use Adder library" FORCE)
    endif()
else()
    message(STATUS "Adder library support disabled")
endif()

if(USE_GLFW)
    target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
endif()

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES ${PROJECT_BINARY_DIR}/herzlich.h DESTINATION include)

# Install vcpkg DLLs alongside the executable
if(WIN32 AND USE_GLFW)
    # Find and install GLFW3 DLL
    find_file(GLFW3_DLL 
        NAMES glfw3.dll 
        PATHS "${CMAKE_PREFIX_PATH}/bin" 
              "${_VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/bin"
    )
    if(GLFW3_DLL)
        install(FILES ${GLFW3_DLL} DESTINATION bin)
    endif()
endif()

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_VERSION_MAJOR "${herzlich_VERSION_MAJOR}")
set(CPACK_VERSION_MINOR "${herzlich_VERSION_MINOR}")
# set(CPACK_GENERATOR "ZIP;NSIS")  # Create both ZIP and NSIS installer
include(CPack)