#include "Player.hpp"


Player::Player(float x, float y, float r, int red, int green, int blue) : Ball(x, y, r, red, green, blue)
{
    // Ball(x, y, r, red, green, blue);
    shape_.setOutlineColor(sf::Color::White);
    shape_.setOutlineThickness(-shape_.getRadius()/20);
    velocity = velocity_factor / r_;
}

Player::~Player() {}

bool Player::intersect(Food &b_) //b1_ - nasza
{
    float d = sqrtf( pow((b_.shape_.getPosition().x-shape_.getPosition().x),2.0f) +  pow((b_.shape_.getPosition().y-shape_.getPosition().y),2.0f) );

    float diff = shape_.getRadius() - eating_difference*b_.shape_.getRadius();
    
    if (diff > d)
    {
        r_ += growth_factor;
        velocity = velocity_factor / r_;
    };
    return diff > d;

}

/*
void Player::growing(Food &b_)
{
    if this.intersect(b_) shape_.setRadius(r+1);

}
*/