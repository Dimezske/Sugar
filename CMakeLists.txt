cmake_minimum_required(VERSION 3.16)
project(SugarApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib REQUIRED)

add_executable(SugarApp
    main.cpp
    sugar.cpp
    coffee.cpp
    ui.cpp
)

target_link_libraries(SugarApp PRIVATE raylib)

if(UNIX AND NOT APPLE)
    target_link_libraries(SugarApp PRIVATE m pthread dl rt X11)
endif()