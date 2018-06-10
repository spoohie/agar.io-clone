/**
*   \class Player
*   \brief A Player class defines all of the abilities that has a moving ball.
*/
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

    Player (float, float, float, int, int, int);
    float velocity; /**< a float numbers representing player's velocity*/
    bool is_intersection; /**< variable used to estimate difference of distance between edges of two balls*/
    sf::Vector2f direction; /**< Normalised vector of direction of the ball*/


    float distanceTo(sf::Vector2f);

    sf::Vector2f normalize(const sf::Vector2f&);

    bool intersect(Ball&, const float &);

    /** Makes ball growing
    *   @param f a Food class object that is being "eaten" by Player's balls
    *   @TODO: think if it's necessary (not implemented)
    */
    void growing(Food& f);

    /** A Player class destructor */
    ~Player ();
};
