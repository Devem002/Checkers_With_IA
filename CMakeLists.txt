cmake_minimum_required(VERSION 3.7)

project(Checkers)
set(CMAKE_CXX_STANDARD 14)

set(SDL2_INCLUDE_DIR C:/CLION/SDL/include)
set(SDL2_LIB_DIR C:/CLION/SDL/lib/x86)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_executable(Checkers Main.cpp utils/sdlfunctions.cpp objects/Drawable.cpp objects/Game.cpp objects/Piece.cpp objects/Player.cpp
        objects/Table.cpp objects/Table.cpp objects/TableBase.cpp objects/players/AI.cpp objects/players/AImove.cpp objects/players/AITable.cpp
        objects/players/Human.cpp)
target_link_libraries(${PROJECT_NAME} SDL2main SDL2)
