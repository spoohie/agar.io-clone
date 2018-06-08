#include "Bot.hpp"

Bot::Bot(float x, float y, float r, int red, int green, int blue) : Player(x, y, r, red, green, blue) {}

void Bot::movement(sf::RenderWindow& window, Player& pilka)
{

    direction = normalize(pilka.returnPosition() - returnPosition());

    if (pilka.returnRadius() >= r_)
    {

        if ((distanceTo(pilka.returnPosition())-r_-pilka.returnRadius()) < chasingDistance) 
        {
            shape_.move(-direction.x*velocity*botVelocityFactor, -direction.y*velocity*botVelocityFactor);
        }

    } else shape_.move(direction.x*velocity*botVelocityFactor, direction.y*velocity*botVelocityFactor);

}
Bot::~Bot() {}
