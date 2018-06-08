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
    sf::Vector2f mouse_pos;
public:
    Bot (float, float, float, int, int, int);
    void movement(sf::RenderWindow &window, Player& pilka, std::vector<Food>& spam);
    virtual ~Bot ();
    int test;
};
