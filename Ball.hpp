#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>

#include "Const.hpp"

class Ball
{

public:
    Ball (float , float , float, int, int, int );

    int returnRadius();
    float x_coeff, y_coeff, r_;
    sf::CircleShape shape_;
    sf::Vector2f returnPosition();

    void update(sf::RenderWindow &window);
    void settingPosition(sf::RenderWindow &window);
    void resettingPosition(sf::RenderWindow &window, float x, float y); // funkcja do ustawiania obiektu w odpowiednim miejscu przy skalowaniu okna

    virtual ~Ball () = 0;
};
