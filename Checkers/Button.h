//
// Created by devem on 10/17/22.
//

#ifndef CHECKERS_BUTTON_H
#define CHECKERS_BUTTON_H
#include "SFML/Graphics.hpp"
using namespace sf;
namespace btn {

    class Button {
    public:
        RectangleShape button();
        Text Button_text();
    private:
        RectangleShape button_;
        Text Button_Text_;
    };

}//btn
#endif //CHECKERS_BUTTON_H
