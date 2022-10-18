//
// Created by devem on 10/17/22.
//

#ifndef CHECKERS_CHECKERS_PIECE_H
#define CHECKERS_CHECKERS_PIECE_H
#include <SFML/Graphics.hpp>

namespace ch {

// Forward declare to allow Piece to have a reference to its Square.
    class Square;

// The actual piece on a checkers board.
    class Piece {
    public:
        Piece(const float &radius,
              const sf::Color &color,
              const float &outlineThickness);

        // Draws the piece to renderWindow.
        void draw(sf::RenderWindow &renderWindow);

        void setPosition(const sf::Vector2f &newPosition);

        void setColor(const sf::Color &newColor);

        void setOutlineColor(const sf::Color &newColor);

        sf::CircleShape getCircle();

        sf::Vector2f getPosition();

    private:
        // Makes up the actual Piece to draw in draw().
        sf::CircleShape circle;
    };

} // namespace ch

#endif //CHECKERS_CHECKERS_PIECE_H
