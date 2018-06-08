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
    sf::Vector2i mouse_pos;
public:
    Bot (float, float, float, int, int, int);
    void movement(sf::RenderWindow &window, sf::Vector2f& playerPosition);
    virtual ~Bot ();
};
