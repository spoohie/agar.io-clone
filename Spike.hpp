/**
*   \class Spike
*   \brief A spike class defines spike balls in the game.
*/
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include "Ball.hpp"

class Spike : public Ball
{
public:
    Spike (float , float , float, int, int, int );
    ~Spike ();
};
