#include "Bot.hpp"

/** A Bot class constructor
*   @param x a float percentage number that defines horizontal position
*   @param y a float percentage number that defines vertical position
*   @param r a float number representing radius of a balls
*   @param red a integer number representing red color in RGB
*   @param green a integer number representing green color in RGB
*   @param blue a integer number representing blue color in RGB
*/
Bot::Bot(float x, float y, float r, int red, int green, int blue) : Player(x, y, r, red, green, blue) {}

/** Bot's movement algorithm implementation
*   @param window a sf::RenderWindow member representing current window
*   @param pilka a Player object representing a player's ball
*   @param spam a vector of food
*/
void Bot::movement(sf::RenderWindow& window, Player& pilka, std::vector<Food>& spam)
{

    /** Makes a bot stay in the bounds of the game window */
    if (returnPosition().x < 0) shape_.setPosition(0, returnPosition().y);
    else if (returnPosition().x > window.getSize().x) shape_.setPosition(window.getSize().x, returnPosition().y);
    if (returnPosition().y < 0) shape_.setPosition(returnPosition().x, 0);
    else if (returnPosition().y > window.getSize().y) shape_.setPosition(returnPosition().x, window.getSize().y);

    // 3IQ bot algorithm

    if (pilka.returnRadius() >= r_)
    {
        if ((distanceTo(pilka.returnPosition())-r_-pilka.returnRadius()) <= chasingDistance)
        {
            direction = normalize(pilka.returnPosition() - returnPosition());
            shape_.move(-direction.x*velocity*botVelocityFactor, -direction.y*velocity*botVelocityFactor);
        }
        else
        {
            Food nextTarget = *std::min_element(std::begin(spam), std::end(spam),
                [&] (Food& s1, Food& s2)
                {
                    return distanceTo(s1.returnPosition()) < distanceTo(s2.returnPosition());
                });

            direction = normalize(nextTarget.returnPosition() - returnPosition());
            shape_.move(direction.x*velocity*botVelocityFactor, direction.y*velocity*botVelocityFactor);
        }

    }
    else
    {
    	direction = normalize(pilka.returnPosition() - returnPosition());
    	shape_.move(direction.x*velocity*botVelocityFactor, direction.y*velocity*botVelocityFactor);
    }

}
Bot::~Bot() {}
