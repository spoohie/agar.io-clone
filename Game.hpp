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
#include "Spike.hpp"
#include "Bot.hpp"

class Game
{
public:
    Game();
    void init(sf::RenderWindow &);
    Gamer pilka(float x, float y, float r, int red, int green, int blue);
    Bot bot(float x, float y, float r, int red, int green, int blue);
    std::vector<Ball*> objects;
    int spamsize;
    int currentWindowX, currentWindowY;
    std::vector<Food> spam;
    std::vector<Spike> spikes;
    ~Game();
};
