#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Ball.hpp"
#include "Food.hpp"
#include "Const.hpp"

class Player : public Ball
{
public:
    Player (float , float , float, int, int, int );
    float velocity;
    //float diff;
    bool wyn;
    float distanceTo(Ball& b_);
    bool intersect(Ball&, const float &proportion);
    void growing(Food&);
    ~Player ();
};
