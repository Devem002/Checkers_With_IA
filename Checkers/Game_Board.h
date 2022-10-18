//
// Created by devem on 10/17/22.
//

#ifndef CHECKERS_GAME_BOARD_H
#define CHECKERS_GAME_BOARD_H
#include "Square.h"
#include <vector>
#include <string>
#include <iostream>

void displayBoard(const std::vector<sq::Square> &sqVect, int widthInUnderscores);
void compactBoard(const std::vector<sq::Square> &sqVect);
void defaultBoard(const std::vector<sq::Square> &sqVect);
void wideBoard(const std::vector<sq::Square> &sqVect);



#endif //CHECKERS_GAME_BOARD_H
