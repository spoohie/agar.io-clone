#include "Gamer.hpp"

Gamer::Gamer(float x, float y, float r, int red, int green, int blue) : Player(x, y, r, red, green, blue) {}

void Gamer::movement(sf::RenderWindow& window)
{
    mouse_pos = sf::Mouse::getPosition(window);
    float diff_x = static_cast<float>(mouse_pos.x) - shape_.getPosition().x;
    float diff_y = static_cast<float>(mouse_pos.y) - shape_.getPosition().y;
    shape_.move(velocity*diff_x,velocity*diff_y);
}

void Gamer::speedup()
{
    if(r_> 2.0f* playerInitSize)
    {
        velocity = std::min(2.0f*velocity,velocityFactor/playerInitSize);
        r_ /= 1.01f;
    } else velocity = velocityFactor/r_;
}

void Gamer::defaultSpeed()
{
    velocity = velocityFactor/r_;
}

Gamer::~Gamer() {}
