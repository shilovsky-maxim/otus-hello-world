cmake_minimum_required(VERSION 3.10)

# set the project name
if(NOT DEFINED ENV{GITHUB_RUN_NUMBER})
    set(ENV{GITHUB_RUN_NUMBER} 1)
endif()

project(helloworld VERSION 0.0.$ENV{GITHUB_RUN_NUMBER})

# add the executable
add_executable(helloworld main.cpp)