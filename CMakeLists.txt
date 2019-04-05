cmake_minimum_required(VERSION 3.13)
project(tanchishe)

set(CMAKE_CXX_STANDARD 11)

aux_source_directory(src dir_srcs)

set(TANCHISHE ${dir_srcs} src/game.cpp src/wall.cpp src/wall.h src/snake.cpp src/snake.h src/food.cpp src/food.h)
add_executable(tanchishe ${TANCHISHE})