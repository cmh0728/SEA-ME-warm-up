cmake_minimum_required(VERSION 3.10)
project(EX00)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

#실행파일이름 설정 및 소스파일들 넣어주기 
add_executable(Car
    main.cpp
    src/Car.cpp
)
