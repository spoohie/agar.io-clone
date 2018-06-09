#include "Bot.hpp"

Bot::Bot(float x, float y, float r, int red, int green, int blue) : Player(x, y, r, red, green, blue) {}

void Bot::movement(sf::RenderWindow& window, Player& pilka, std::vector<Food>& spam)
{

    // utrzymuje obiekt w mapie
    if (returnPosition().x < 0) shape_.setPosition(0, returnPosition().y);
    else if (returnPosition().x > window.getSize().x) shape_.setPosition(window.getSize().x, returnPosition().y);

    if (returnPosition().y < 0) shape_.setPosition(returnPosition().x, 0);
    else if (returnPosition().y > window.getSize().y) shape_.setPosition(returnPosition().x, window.getSize().y);

    // wektor jednostkowy kierunku (bedzie mnozony przez predkosc)
    direction = normalize(pilka.returnPosition() - returnPosition());


    // caly algorytm 3IQ Bota

    // jesli bot jest mniejszy od gracza:
    if (pilka.returnRadius() >= r_)
    {

        //jesli bot jest w strefie zagrozenia...
        if ((distanceTo(pilka.returnPosition())-r_-pilka.returnRadius()) <= chasingDistance) 
        {   
            // ...to spierdala
            shape_.move(-direction.x*velocity*botVelocityFactor, -direction.y*velocity*botVelocityFactor);
        }
        else
        {
            // a jak jest bezpieczny to skanuje jedzonka i szuka najblizszego
            nextTarget = *std::min_element(std::begin(spam), std::end(spam),
                [&] (Food& s1, Food& s2)
                {
                    return distanceTo(s1.returnPosition()) < distanceTo(s2.returnPosition());
                });

            direction = normalize(nextTarget.returnPosition() - returnPosition());
            shape_.move(direction.x*velocity*botVelocityFactor, direction.y*velocity*botVelocityFactor);
        }

    } else shape_.move(direction.x*velocity*botVelocityFactor, direction.y*velocity*botVelocityFactor); // ten else sie wykonuje jak bot jest wiekszy 

}
Bot::~Bot() {}
