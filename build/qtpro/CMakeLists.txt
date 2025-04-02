cmake_minimum_required(VERSION 3.10)
project(qtpro VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

add_executable(qtpro main.cpp)

target_link_libraries(qtpro PRIVATE Qt5::Widgets)