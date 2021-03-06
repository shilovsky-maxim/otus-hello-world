cmake_minimum_required(VERSION 3.10)

# set the project name
if(NOT DEFINED ENV{GITHUB_RUN_NUMBER})
    set(ENV{GITHUB_RUN_NUMBER} 1)
endif()
list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

project(helloworld VERSION 0.0.$ENV{GITHUB_RUN_NUMBER})
include(conan.cmake)
conan_cmake_configure(REQUIRES boost/1.77.0
                      GENERATORS cmake_find_package)

conan_cmake_autodetect(settings)

conan_cmake_install(PATH_OR_REFERENCE .
                    BUILD missing
                    REMOTE conancenter
                    SETTINGS ${settings})

configure_file(version.h.in version.h)

add_library(hwlib lib.cpp)
add_executable(helloworld main.cpp)

enable_testing()
add_subdirectory(tests)

target_include_directories(hwlib
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
    target_compile_options(helloworld PRIVAT-E
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

install(TARGETS helloworld RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT max-in-3d@ngs.ru)

include(CPack)


