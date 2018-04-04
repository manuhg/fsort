cmake_minimum_required(VERSION 2.8.8)

find_package(Caffe)

include_directories(${Caffe_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/../include)
link_directories(${CMAKE_SOURCE_DIR}/../lib)

add_definitions(${Caffe_DEFINITIONS})

set(GXX_FLAGS "-Os -fdata-sections -ffunction-sections")
set(LD_FLAGS "-Wl,--gc-sections")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GXX_FLAGS}" )
#set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${LD_FLAGS}" )

file(GLOB CPP_FILES ./*.cpp)
file(GLOB INCLUDES ./*.h)
set(LIBS bhtsne ${Caffe_LIBRARIES})


add_executable(fsort ${INCLUDES} ${CPP_FILES})
target_link_libraries(fsort ${LIBS})

