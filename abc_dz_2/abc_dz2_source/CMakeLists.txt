# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# project name and language
project(abc_dz2 LANGUAGES CXX)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")

# Source files list
set(SOURCE_FILES
        # Headers
        classes/vehicle.h
        classes/truck.h
        classes/bus.h
        classes/car.h
        container/container.h

        # Sources
        classes/vehicle.cpp
        classes/truck.cpp
        classes/bus.cpp
        classes/car.cpp
        container/container.cpp
        main.cpp
        )

add_executable(task01 ${SOURCE_FILES})
