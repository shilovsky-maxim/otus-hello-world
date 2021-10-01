cmake_minimum_required(VERSION 3.10)
project(PackageTest CXX)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(version_validity version_validity.cpp)
add_executable(output_validity output-test.cpp)


set_target_properties(version_validity output_validity PROPERTIES
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_include_directories(version_validity PRIVATE "..")
target_include_directories(output_validity PRIVATE "..")

target_link_libraries(version_validity
    ${Boost_LIBRARIES}
    hwlib
)

target_link_libraries(output_validity
    ${Boost_LIBRARIES}
    hwlib
)

add_test(version_validity "${CMAKE_BINARY_DIR}/tests/version_validity")
add_test(output_validity "${CMAKE_BINARY_DIR}/tests/output_validity")