cmake_minimum_required(VERSION 3.10)

# set the project name
if(NOT DEFINED ENV{GITHUB_RUN_NUMBER})
    set(ENV{GITHUB_RUN_NUMBER} 1)
endif()

project(helloworld VERSION 0.0.$ENV{GITHUB_RUN_NUMBER})

configure_file(version.h.in version.h)

# add the executable
add_executable(helloworld main.cpp)
add_library(hwlib lib.cpp)

target_include_directories(helloworld
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_link_libraries(helloworld PRIVATE
    hwlib
)

