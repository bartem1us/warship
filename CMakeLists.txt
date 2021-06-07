cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set( CMAKE_INCLUDE_PATH "/usr/include")
set( CMAKE_LIBRARY_PATH "/usr/lib/x86_64-linux-gnu/libncurses.so")
option(BUILD_EXAMPLES "Build examples" ON)
option(BUILD_TESTS "Build tests" ON)


project(DZ)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_library(${PROJECT_NAME} STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/
 include/game_ship.h sources/game_ship.cpp)

add_executable(demo
        ${CMAKE_CURRENT_SOURCE_DIR}/demo/main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:include>")

install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}-config
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )

target_link_libraries(demo ${CURSES_LIBRARIES})
target_link_libraries(demo ${PROJECT_NAME})
