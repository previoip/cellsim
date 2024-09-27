cmake_minimum_required(VERSION 3.10)
project(cellsim VERSION 0.0.1)
set(CMAKE_C_FLAGS "-std=c99")

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(cellsim cellsim/cellsim.c)
target_link_libraries(cellsim -lfreeGLUT -lOpenGL32)
