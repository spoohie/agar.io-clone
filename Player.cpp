#include "Player.hpp"


Player::Player(float x, float y, float r, int red, int green, int blue) : Ball(x, y, r, red, green, blue)
{
    shape_.setOutlineColor(sf::Color::White);
    shape_.setOutlineThickness(-shape_.getRadius()/20);
    velocity = velocityFactor / r_;
}

Player::~Player() {}

bool Player::intersect(Food &b_)
{
    float d = sqrtf( pow((b_.shape_.getPosition().x-shape_.getPosition().x),2.0f) +    pow((b_.shape_.getPosition().y-shape_.getPosition().y),2.0f) );

    float diff = shape_.getRadius() - eatingDifference*b_.shape_.getRadius();

    if (diff > d)
    {
          r_ += growthFactor;
          velocity = velocityFactor / r_;
    };
    return diff > d;
}
