cmake_minimum_required(VERSION 2.8)

project(DBtest)

set(CMAKE_CXX_COMPILER "g++")

set(CMAKE_CXX_FLAGS "-lpqxx -lpq")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

aux_source_directory(./ SRC_LIST)

aux_source_directory(./other OTHER_SRC_LIST)

#list(APPEND SRC_LIST ${OTHER_SRC_LIST})

#include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(DBtest ${SRC_LIST})





