# prerequisites

## SDL2

### build from source (win)

1. clone https://github.com/libsdl-org/SDL.git to any empty folder and cd
2. run `cmake -S . -B build/release -G <generator> -DCMAKE_INSTALL_PATH=<rel-or-abs-path> -DCMAKE_BUILD_TYPE=Release`
3. run `cmake --build build/release --target install`
4. copy following into `${DCMAKE_INSTALL_PATH}/sdl2-config.cmake`

```cmake
set(SDL2_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/include")

# Support both 32 and 64 bit builds
if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
  set(SDL2_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2.lib;${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2main.lib")
else ()
  set(SDL2_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2.lib;${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2main.lib")
endif ()

string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)
```