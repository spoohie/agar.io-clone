#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Ball.hpp"
#include "Food.hpp"
#include "Const.hpp"

class Player : public Ball 
{
public:
    Player (float , float , float, int, int, int );
    float velocity;
    bool intersect(Food&);
    void growing(Food&);
    ~Player ();
};
