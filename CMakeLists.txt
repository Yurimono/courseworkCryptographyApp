cmake_minimum_required(VERSION 3.16)

project(CipherApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(Qt6_DIR "D:/Programs/Qt/6.9.0/msvc2022_64/lib/cmake/Qt6")
find_package(Qt6 COMPONENTS Widgets REQUIRED)

qt_add_executable(CipherApp
    main.cpp
    cipherfunctions.h
    caesar.cpp
    vigenere.cpp
)

target_link_libraries(CipherApp PRIVATE Qt::Widgets)