#include <iostream>
#include <random>     //random numbers
#include <functional> //std::bind
#include <SFML/Window.hpp>
#include <boost/range/algorithm.hpp>

#include "Ball.hpp"
#include "Const.hpp"
#include "Player.hpp"
#include "Food.hpp"
#include "Gamer.hpp"

class Game
{
public:
    Game();
    void init();
    Gamer pilka(float x, float y, float r, int red, int green, int blue);
    std::vector<Food> spam;
    sf::ContextSettings contextSettings_;
    ~Game();
};
