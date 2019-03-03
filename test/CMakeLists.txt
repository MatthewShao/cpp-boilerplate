cmake_minimum_required(VERSION 3.3)

set(MODULES ../cmake_modules)
set(SRC ../src)

project(Test)

project(Example)

include(CTest)
enable_testing()

include(${MODULES}/DownloadProject.cmake)
download_project(
        PROJ                googletest
        GIT_REPOSITORY      https://github.com/google/googletest.git
        GIT_TAG             master
        UPDATE_DISCONNECTED 1
)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)

file(GLOB SOURCES ${SRC}/*.cpp)
list(FILTER SOURCES EXCLUDE REGEX ".*main.cpp$")
# **For Debug A List**
foreach(file ${SOURCES})
    message(STATUS ${file})
endforeach(file)
file(GLOB HEADERS ${SRC}/*.h)
file(GLOB TESTS *.cpp)

add_executable(test gtest.cpp ${TESTS} ${SOURCES} ${HEADERS} utils.cpp utils.h)
target_link_libraries(test gtest gmock template)

if(CMAKE_COMPILER_IS_GNUCXX)
    include(${MODULES}/CodeCoverage.cmake)
    APPEND_COVERAGE_COMPILER_FLAGS()
    set(COVERAGE_LCOV_EXCLUDES '/usr/*' 'gtest/*')
    SETUP_TARGET_FOR_COVERAGE_LCOV(NAME coverage
            EXECUTABLE test
            DEPENDENCIES test)
    add_custom_command(TARGET coverage
            PRE_BUILD
            COMMAND echo "Removing old report..."
            COMMAND rm -rf ../*/test/coverage
            )
endif()

# **For Debug A List**
#foreach(file ${SOURCES})
#    message(STATUS ${file})
#endforeach(file)