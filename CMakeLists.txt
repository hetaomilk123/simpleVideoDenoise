# CMake version limit
cmake_minimum_required(VERSION 2.8)

# project info (1)
project(simpleVideoDenoise)

# include path (2)
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src)

#  bin path
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../bin)

# debug version
SET(CMAKE_BUILD_TYPE "release")
if (CMAKE_BUILD_TYPE STREQUAL debug)
    add_definitions(-D_DEBUG)
endif ()
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb -std=c++11")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -std=c++11")


aux_source_directory(src DIR_SRCS)

# (3)
add_executable(simpleVideoDenoise ${DIR_SRCS})

# something about OpenCV
find_package(OpenCV REQUIRED)
target_link_libraries(simpleVideoDenoise ${OpenCV_LIBS})
