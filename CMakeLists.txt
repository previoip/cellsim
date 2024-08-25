cmake_minimum_required(VERSION 3.10)
project(cellsim VERSION 0.0.1)
set(CMAKE_C_FLAGS "-std=c99")

include(ExternalProject)

set(SDL_PREFIX_DIR SDL-2.30.6)

ExternalProject_Add(
  SDL2
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG release-2.30.6
  PREFIX ${SDL_PREFIX_DIR}
  BINARY_DIR ${SDL_PREFIX_DIR}/src/SDL2-build
  CMAKE_COMMAND ${THIRD_PARTY_CMAKE_COMMAND}
  CMAKE_ARGS ${build_type_arg} -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
  UPDATE_COMMAND ""
  # BUILD_COMMAND cmake --build <BINARY_DIR>
  # INSTALL_COMMAND cmake --build <BINARY_DIR> --target install
  BUILD_COMMAND ""
  INSTALL_COMMAND ""
)

set(SDL2_INCLUDE_DIR ${CMAKE_CURRENT_BINARY_DIR}/${SDL_PREFIX_DIR}/include)
set(SDL2_LIB_DIR  ${CMAKE_CURRENT_BINARY_DIR}/${SDL_PREFIX_DIR}/lib)

add_executable(cellsim cellsim/cellsim.c)
