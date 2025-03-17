cmake_minimum_required(VERSION 3.7)

project(3ddist_test_app VERSION 1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(HEADERS
    Point3D.h
    Vector3D.h
    Segment3D.h
    Matrix.h
)

set(SOURCES
    Point3D.cpp
    Vector3D.cpp
    Segment3D.cpp
    Matrix.cpp
    main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} )


