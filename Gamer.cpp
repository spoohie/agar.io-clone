#include "Gamer.hpp"

/** A Bot class constructor
*   @param x a float percentage number that defines horizontal position
*   @param y a float percentage number that defines vertical position
*   @param r a float number representing radius of a balls
*   @param red a integer number representing red color in RGB
*   @param green a integer number representing green color in RGB
*   @param blue a integer number representing blue color in RGB
*/
Gamer::Gamer(float x, float y, float r, int red, int green, int blue) : Player(x, y, r, red, green, blue) {}

/** Implementation of player's ball moving features
*   @param window a sf::RenderWindow member representing current window
*/
void Gamer::movement(sf::RenderWindow& window)
{
    // utrzymuje obiekt w mapie
    if (returnPosition().x < 0) shape_.setPosition(0, returnPosition().y);
    else if (returnPosition().x > window.getSize().x) shape_.setPosition(window.getSize().x, returnPosition().y);

    if (returnPosition().y < 0) shape_.setPosition(returnPosition().x, 0);
    else if (returnPosition().y > window.getSize().y) shape_.setPosition(returnPosition().x, window.getSize().y);

    mouse_pos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
    direction = normalize(mouse_pos - shape_.getPosition());
    toMouseDistance = distanceTo(mouse_pos);
    if (toMouseDistance > 40)
    {
        shape_.move(direction.x*velocity, direction.y*velocity);
    }
    else
    {
        shape_.move(direction.x*toMouseDistance*velocity/40, direction.y*velocity*toMouseDistance/40);
    }
}
/** Speeding up function after pressing spacebar */
void Gamer::speedup()
{
    if(r_> 1.0f* playerInitSize)
    {
        velocity = std::min(2.0f*velocity,velocityFactor/playerInitSize);
        r_ /= 1.01f;
    } else velocity = velocityFactor/r_;
}
/** Calculating and setting default speed for the ball */
void Gamer::defaultSpeed()
{
    velocity = velocityFactor/r_;
}

Gamer::~Gamer() {}
