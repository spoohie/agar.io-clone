#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Const.hpp"
class Gamer : public Player
{
private:
    sf::Vector2f mouse_pos;
    float toMouseDistance;
public:
    Gamer (float, float, float, int, int, int);

    void movement(sf::RenderWindow &window);
    void speedup();
    void defaultSpeed();
    
    virtual ~Gamer ();
};
