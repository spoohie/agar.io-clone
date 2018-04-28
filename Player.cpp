#include "Player.hpp"


Player::Player(float x, float y, float r, int red, int green, int blue) : Ball(x, y, r, red, green, blue)
{
    // Ball(x, y, r, red, green, blue);
    shape_.setOutlineColor(sf::Color::White);
    shape_.setOutlineThickness(-shape_.getRadius()/20);
}

Player::~Player() {}

bool Player::intersect(Food b2_) //b1_ - nasza
{
    float d = sqrtf( pow((b2_.shape_.getPosition().x-shape_.getPosition().x),2.0f) +  pow((b2_.shape_.getPosition().y-shape_.getPosition().y),2.0f) );

    float diff = shape_.getRadius() - b2_.shape_.getRadius();

    return diff > d;

}
