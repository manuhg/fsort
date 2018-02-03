cmake_minimum_required(VERSION 2.8)
project (fsort)
find_package(OpenCV REQUIRED)
find_package(glfw3 3.2 REQUIRED)
find_package(OpenGL REQUIRED)
add_executable(fsort fsort.cpp)
include_directories(${OPENGL_INCLUDE_DIR})
target_link_libraries(fsort ${OpenCV_LIBS} /usr/lib/libglfw.so.3.2 ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY})


