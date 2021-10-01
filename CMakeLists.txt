cmake_minimum_required(VERSION 3.10)

# set the project name
if(NOT DEFINED ENV{GITHUB_RUN_NUMBER})
    set(ENV{GITHUB_RUN_NUMBER} 1)
endif()

project(helloworld VERSION 0.0.$ENV{GITHUB_RUN_NUMBER})
list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})
include(conan.cmake)
conan_cmake_configure(REQUIRES boost/1.77.0
                      GENERATORS cmake_find_package)

conan_cmake_autodetect(settings)

conan_cmake_install(PATH_OR_REFERENCE .
                    BUILD missing
                    REMOTE conancenter
                    SETTINGS ${settings})
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.h.in version.h)

# add the executable
add_library(hwlib lib.cpp)
add_executable(helloworld main.cpp)
add_executable(helloworld_tests tests.cpp)

target_include_directories(helloworld
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_link_libraries(helloworld PRIVATE
    hwlib
)

set_target_properties(helloworld hwlib helloworld_tests PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

set_target_properties(helloworld_tests PROPERTIES
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(helloworld_tests
    ${Boost_LIBRARIES}
    hwlib
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

enable_testing()

add_test(test helloworld_tests)