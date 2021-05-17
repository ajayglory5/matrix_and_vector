cmake_minimum_required(VERSION 3.20)

# Activating C++ 14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCES 
    matrix_test.cpp
    vector_test.cpp
    test_utils.cpp
    )

add_executable(${PROJECT_NAME}_test ${SOURCES})

target_link_libraries(
    ${PROJECT_NAME}_test 
    PUBLIC 
    ${PROJECT_NAME}
    gtest 
    gmock
    )

target_include_directories(
    ${PROJECT_NAME}_test 
    PUBLIC 
    include 
    ${CMAKE_SOURCE_DIR}/src/include
    )
