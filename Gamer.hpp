/**
*   \class Gamer
*   \brief A class representing a ball controlled by player's mouse.
*/
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Const.hpp"
class Gamer : public Player
{
private:
    sf::Vector2f mouse_pos; /**< Position of a player's mouse */
    float toMouseDistance; /**< float number defining ball distance to mouse current position */
public:
    Gamer (float, float, float, int, int, int);

    void movement(sf::RenderWindow &window);
    void speedup();
    void defaultSpeed();

    virtual ~Gamer ();
};
