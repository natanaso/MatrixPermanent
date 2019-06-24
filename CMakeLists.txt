cmake_minimum_required(VERSION 2.6)
project(permanent)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wno-deprecated-declarations")


INCLUDE_DIRECTORIES(include)

FIND_PACKAGE(Eigen3 REQUIRED)
INCLUDE_DIRECTORIES(${EIGEN3_INCLUDE_DIR})

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
ADD_EXECUTABLE(test_permanent src/test_permanent.cpp src/permanent.cpp)

