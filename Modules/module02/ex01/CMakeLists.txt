cmake_minimum_required(VERSION 3.10)
project(EX01)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(mycar
    main.cpp
    src/MyCarModel.cpp
)