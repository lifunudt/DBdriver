cmake_minimum_required(VERSION 2.8)

MESSAGE( ${PROJECT_SOURCE_DIR} )

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(DBtest testDB.cpp DBdriverpgsql.cpp)






