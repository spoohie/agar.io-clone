/**
*   \class Bot
*   \brief Class defines a Bot player, whose movement is automaticly calculated.
*
*/
#include <iostream>
#include <math.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Const.hpp"
class Bot : public Player
{
private:
    sf::Vector2f mouse_pos; /**< Position of a player's mouse */

public:
    Bot (float, float, float, int, int, int);
    void movement(sf::RenderWindow &window, Player& pilka, std::vector<Food>& spam);

    ~Bot ();
};
