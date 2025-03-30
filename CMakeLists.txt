cmake_minimum_required(VERSION 3.27.3)

project(step-editor C)

if(${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Linux")
    set(PYTHON_EXECUTABLE "python3")
elseif(${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Windows")
    set(PYTHON_EXECUTABLE "python")
else()
    set(PYTHON_EXECUTABLE "python3")
endif()

set(CMAKE_GENERATOR "Ninja" CACHE INTERNAL "" FORCE)

set(CMAKE_MAKE_PROGRAM ../modules/ninja/ninja CACHE FILEPATH "")
set(CMAKE_EXECUTABLE_SUFFIX .exe)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_executable(${PROJECT_NAME})

execute_process(
    COMMOND ${PYTHON_EXECUTABLE}
    ${CMAKE_CURRENT_SOURCE_DIR}/sequence-generator.py
    -i ${CMAKE_CURRENT_SOURCE_DIR}/sequence.json
    -o ${CMAKE_BINARY_DIR}/sequence.h
)

target_sources(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)
