cmake_minimum_required(VERSION 2.8)
project( CaptureVideo )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( CaptureVideo src/CaptureVideo.cpp )
target_link_libraries( CaptureVideo ${OpenCV_LIBS} )