#include "Player.hpp"

/** A  Player class constructor
*   @param x a float percentage number that defines horizontal position
*   @param y a float percentage number that defines vertical position
*   @param r a float number representing radius of a balls
*   @param red a integer number representing red color in RGB
*   @param green a integer number representing green color in RGB
*   @param blue a integer number representing blue color in RGB
*/
Player::Player(float x, float y, float r, int red, int green, int blue) : Ball(x, y, r, red, green, blue)
{
    shape_.setOutlineColor(sf::Color::White);
    shape_.setOutlineThickness(-shape_.getRadius()/20);
    velocity = velocityFactor / r_;
}
/** Distance from ball to certain vector
*   @param v_ vector of coordinates to some point
*/
float Player::distanceTo(sf::Vector2f v_)
{
    return sqrtf(pow((v_.x-returnPosition().x),2.0f) + pow((v_.y-returnPosition().y),2.0f) );
}
/** Creates a normalized vector
*   @param source vector of coordinates to some source point
*/
sf::Vector2f Player::normalize(const sf::Vector2f& source)
{
    float length = sqrt((source.x * source.x) + (source.y * source.y));
    if (length != 0)
        return sf::Vector2f(source.x / length, source.y / length);
    else
        return source;
}
/** Checks if player's and other ball have intersect region
*   @param v_ is a Ball's coordinates vector that will intersect refer to
*   @param proportion a const float reference defining how much intersection is needed to be "intersected"
*/
bool Player::intersect(Ball& b_, const float &proportion)
{

    is_intersection = shape_.getRadius() - proportion*b_.shape_.getRadius() > distanceTo(b_.returnPosition());
    if (is_intersection)
    {
          r_ += growthFactor;
          velocity = velocityFactor / r_;
    };
    return is_intersection;
}

Player::~Player() {}
