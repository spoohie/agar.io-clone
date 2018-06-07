#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>

#include "Const.hpp"

class Ball
{

public:
    sf::CircleShape shape_;
    float x_coeff, y_coeff, r_;
    Ball (float , float , float, int, int, int );

    void update(sf::RenderWindow &window);
    void settingPosition(sf::RenderWindow &window);
    sf::Vector2f returnPosition();

    virtual ~Ball () = 0;
};
