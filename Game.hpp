/**
*   \class Game
*   \brief A game class representing all that's happening during game.
*/
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

    int spamsize; /**< a integer number, amount of food existing in game */
    int currentWindowX; /**< a integer number, width of window */
    int currentWindowY; /**< a integer number, height of window */
    std::vector<Food> spam; /**< a vector of food*/
    std::vector<Spike> spikes; /**< a vector of spikes*/

    void init(sf::RenderWindow &);
    Gamer pilka(float x, float y, float r, int red, int green, int blue);
    Bot bot(float x, float y, float r, int red, int green, int blue);

    ~Game();
};
