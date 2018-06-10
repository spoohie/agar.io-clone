/**
*   \class Food
*   \brief Represents a food available for player and bot to be eaten for growth.
*/
#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include "Ball.hpp"

class Food : public Ball
{
public:
    Food (float , float , float, int, int, int );
    ~Food ();
};
