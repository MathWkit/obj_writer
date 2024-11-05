cmake_minimum_required(VERSION 3.29)
project(Objwriter)

set(CMAKE_CXX_STANDARD 20)

add_executable(Objwriter main.cpp
        ObjWriter.cpp
        Polygon.cpp
        Vector2D.cpp
        Vector3D.cpp
)

add_subdirectory(Google_tests)