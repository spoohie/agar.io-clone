#include "Player.hpp"


Player::Player(float x, float y, float r, int red, int green, int blue) : Ball(x, y, r, red, green, blue)
{
    shape_.setOutlineColor(sf::Color::White);
    shape_.setOutlineThickness(-shape_.getRadius()/20);
    velocity = velocityFactor / r_;
}

Player::~Player() {}

float Player::distanceTo(Ball& b_)
{
    return sqrtf(pow((b_.returnPosition().x-returnPosition().x),2.0f) + pow((b_.returnPosition().y-returnPosition().y),2.0f) );
}

sf::Vector2f Player::normalize(const sf::Vector2f& source)
{
    float length = sqrt((source.x * source.x) + (source.y * source.y));
    if (length != 0)
        return sf::Vector2f(source.x / length, source.y / length);
    else
        return source;
}

bool Player::intersect(Ball& b_, const float &proportion)
{
    //d = distanceTo(b_);

    //diff = shape_.getRadius() - proportion*b_.shape_.getRadius();

    is_intersection = shape_.getRadius() - proportion*b_.shape_.getRadius() > distanceTo(b_);
    if (is_intersection)
    {
          r_ += growthFactor;
          velocity = velocityFactor / r_;
    };
    return is_intersection;
}
