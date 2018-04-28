#include "Player.hpp"


Player::Player(float x, float y, float r, int red, int green, int blue) : Ball(x, y, r, red, green, blue)
{
    // Ball(x, y, r, red, green, blue);
    shape_.setOutlineColor(sf::Color::White);
    shape_.setOutlineThickness(-shape_.getRadius()/20);
}

Player::~Player() {}
