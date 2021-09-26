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

set_target_properties(helloworld hwlib PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

if (MSVC)
    target_compile_options(helloworld PRIVATE
        /W4
    )
    target_compile_options(hwlib PRIVATE
        /W4
    )
else ()
    target_compile_options(helloworld PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(hwlib PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

