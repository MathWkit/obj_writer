cmake_minimum_required(VERSION 3.29)
project(Objwriter)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} ${CPPS} ${HPP}
        main.cpp
        ObjWriter.cpp
        Polygon.cpp
        Vector2D.cpp
        Vector3D.cpp
        ObjWriter.h
        Polygon.h
        Vector2D.h
        Vector3D.h
)

add_subdirectory(Google_tests)
