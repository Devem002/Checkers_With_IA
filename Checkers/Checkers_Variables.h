//
// Created by devem on 10/17/22.
//

#ifndef CHECKERS_CHECKERS_VARIABLES_H
#define CHECKERS_CHECKERS_VARIABLES_H
#include <string>
#include <vector>
#include <iostream>
#include <exception>
#include "Square.h"
#include "Checkers_Board.h"

namespace checkers
{
    extern std::vector<sq::Square> squares;
    extern std::string selection; //all input by the user is held by this variable
    extern char turn; //either 'r' (Red) or 'b' (Black)
    extern char captureDirection; //either 'R' (right) or 'L' (left)
    extern char initialRowParity; //either 'O' (odd) or 'E' (even)
    extern bool wasCapture; //was there a capture this turn?
    //used to determine whether to check for consecutive capture
    extern char loser; //either 'r' (Red) or 'b' (Black)
    //who is the loser?

    //for vector location:
    extern int selected; //holds vector address of square of selected piece
    extern int targeted; //holds vector address of square to move a piece to
    extern int inBetween; //holds vector address of square in between the
    //selected and targeted squares (in case of capture)

    extern ch::Board gameBoard;
} // namespace checkers


#endif //CHECKERS_CHECKERS_VARIABLES_H
