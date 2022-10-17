cmake_minimum_required(VERSION 3.23)
project(Checkers)

set(CMAKE_CXX_STANDARD 14)

add_executable(Checkers Checkers/main.cpp Checkers/Error.cpp Checkers/Error.h Checkers/Button.cpp Checkers/Button.h Checkers/Filler.cpp Checkers/Filler.h Checkers/Square.cpp Checkers/Square.h Checkers/Constants.cpp Checkers/Constants.h Checkers/Game_Board.cpp Checkers/Game_Board.h Checkers/Checkers_Board.cpp Checkers/Checkers_Board.h Checkers/Checkers_Piece.cpp Checkers/Checkers_Piece.h Checkers/Checkers_Square.cpp Checkers/Checkers_Square.h Checkers/Checkers_Functions.cpp Checkers/Checkers_Functions.h Checkers/Checkers_Variables.cpp Checkers/Checkers_Variables.h)
