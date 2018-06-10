/**
*   \class Ball
*   \brief A class defining basic features of every ball.
*/
#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>

#include "Const.hpp"

class Ball
{
private:

public:
    Ball (float , float , float, int, int, int );

    float x_coeff, y_coeff, r_; /**< x, y position coeffs and r - radius */
    sf::CircleShape shape_; /**< shape container for circle */

    int returnRadius(); /**< A function to return radius if needed */
    sf::Vector2f returnPosition(); /** A function to return position if needed */

    void update(sf::RenderWindow &window);
    void settingPosition(sf::RenderWindow &window);
    void resettingPosition(sf::RenderWindow &window, float x, float y);

    virtual ~Ball () = 0; /**< Not possible to make Ball object */
};
