cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_EXAMPLES "Build examples" ON)
option(BUILD_TESTS "Build tests" ON)



project(DZ)

add_library(${PROJECT_NAME} STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/
        sources/educational_divisions.cpp
        sources/scientific_divisions.cpp
        sources/DBscientific_divisions.cpp
        sources/DBeducational_divisions.cpp
        sources/Intruction.cpp
        include/dop_function.h sources/dop_function.cpp include/DBhybrid.h)

add_executable(demo
        ${CMAKE_CURRENT_SOURCE_DIR}/examples/demo.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:include>")

target_link_libraries(demo ${PROJECT_NAME})