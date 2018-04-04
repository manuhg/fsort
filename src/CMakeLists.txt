cmake_minimum_required(VERSION 2.8.8)

find_package(Caffe)
include_directories(${Caffe_INCLUDE_DIRS})
include_directories(${CMAKE_BUILD_DIR}../include)
add_definitions(${Caffe_DEFINITIONS})

file(GLOB CPP_FILES ./*.cpp)
file(GLOB INCLUDES ./*.h)

add_executable(fsort_fe ${INCLUDES} ${CPP_FILES})
target_link_libraries(fsort_fe ${Caffe_LIBRARIES})
