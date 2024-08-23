set(SOURCE_PATH "${CMAKE_CURRENT_LIST_DIR}")
set(BUILD_PATH "${SOURCE_PATH}/build")

if(WIN32)
    set(GENERATOR "MinGW Makefiles")
elseif(APPLE)
    set(GENERATOR "Xcode")
else()
    set(GENERATOR "Ninja")
endif()

if(EXISTS "${SOURCE_PATH}/locale.cmake")
    include("${SOURCE_PATH}/locale.cmake")
endif()

if(NOT EXISTS "${BUILD_PATH}/CMakeCache.txt")
    file(MAKE_DIRECTORY "${BUILD_PATH}")
    execute_process(
        # CMAKE_ARGS on next line must not be quoted
        COMMAND "${CMAKE_COMMAND}" -S "${SOURCE_PATH}" -B . -G "${GENERATOR}" ${CMAKE_ARGS}
        WORKING_DIRECTORY "${BUILD_PATH}"
        RESULT_VARIABLE EXIT_STATUS
    )
    if(NOT "${EXIT_STATUS}" EQUAL "0")
        file(REMOVE "${BUILD_PATH}/CMakeCache.txt") # force CMake to run again next time
        message(FATAL_ERROR "CMake failed with status ${EXIT_STATUS}.")
    endif()
endif()

execute_process(
    COMMAND "${CMAKE_COMMAND}" --build .
    WORKING_DIRECTORY "${BUILD_PATH}"
    RESULT_VARIABLE EXIT_STATUS
)
if(NOT "${EXIT_STATUS}" EQUAL "0")
    message(FATAL_ERROR "${GENERATOR} failed with status ${EXIT_STATUS}.")
endif()
