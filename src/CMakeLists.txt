cmake_minimum_required(VERSION 2.8)

MESSAGE( ${PROJECT_SOURCE_DIR} )

find_package( OpenCV REQUIRED )

include_directories(${PROJECT_SOURCE_DIR}/include)

SET(SRC_LIST testDB.cpp DBdriverpq.cpp CameraModel.cpp Link.cpp SensorData.cpp Signature.cpp Transform.cpp )

add_executable(DBtest ${SRC_LIST} )






