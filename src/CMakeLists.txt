cmake_minimum_required(VERSION 3.6)

project(template CXX)

file(GLOB SOURCES *.cpp)
file(GLOB HEADERS *.h)

list(FILTER SOURCES EXCLUDE REGEX ".*main.cpp$")

add_library(template ${SOURCES} ${HEADERS})
add_executable(main main.cpp)
target_link_libraries(main template)