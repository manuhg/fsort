cmake_minimum_required(VERSION 2.8)
project (fsort)
find_package(OpenCV REQUIRED)
add_executable(cvtry cvtry.cpp)
target_link_libraries(cvtry ${OpenCV_LIBS})

