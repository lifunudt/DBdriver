cmake_minimum_required(VERSION 2.8)

project(testpq)

#MESSAGE( ${PROJECT_SOURCE_DIR}/include )

set(CMAKE_CXX_COMPILER "g++")

set(CMAKE_CXX_FLAGS "-lpqxx -lpq")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(/Users/lifu/Documents/DBdriver/include)

#add_subdirectory(src bin)

add_executable(testpq testpq.cpp )






