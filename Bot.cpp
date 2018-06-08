#include "Bot.hpp"

Bot::Bot(float x, float y, float r, int red, int green, int blue) : Player(x, y, r, red, green, blue) {}

void Bot::movement(sf::RenderWindow& window, Player& pilka, std::vector<Food>& spam)
{

    direction = normalize(pilka.returnPosition() - returnPosition());

    if (pilka.returnRadius() >= r_)
    {

        if ((distanceTo(pilka.returnPosition())-r_-pilka.returnRadius()) <= chasingDistance) 
        {
            shape_.move(-direction.x*velocity*botVelocityFactor, -direction.y*velocity*botVelocityFactor);
        }
        else
        {
            Food gdzie = *std::min_element(std::begin(spam), std::end(spam),
                [&] (Food& s1, Food& s2)
                {
                    return distanceTo(s1.returnPosition()) < distanceTo(s2.returnPosition());
                });

            direction = normalize(gdzie.returnPosition() - returnPosition());
            std::cout << "x: " << gdzie.returnPosition().x << " y: " << gdzie.returnPosition().y << std::endl;
            shape_.move(direction.x*velocity*botVelocityFactor, direction.y*velocity*botVelocityFactor);
            //for(const auto& spam_ : spam) distanceTo(spam_.returnPosition());
        }

    } else shape_.move(direction.x*velocity*botVelocityFactor, direction.y*velocity*botVelocityFactor);

}
Bot::~Bot() {}
