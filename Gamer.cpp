#include "Gamer.hpp"

Gamer::Gamer(float x, float y, float r, int red, int green, int blue) : Player(x, y, r, red, green, blue) {}

void Gamer::movement(sf::RenderWindow& window)
{
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

    //diff_x = static_cast<float>(mouse_pos.x) - shape_.getPosition().x;
    //diff_y = static_cast<float>(mouse_pos.y) - shape_.getPosition().y;
    /*
    if(sqrt(pow(diff_x, 2.0)+pow(diff_y, 2.0)) > 100.0)
    {
        shape_.move(velocity*diff_x*0.8,velocity*diff_y*0.8);
    } else shape_.move(velocity*diff_x,velocity*diff_y);*/
}

void Gamer::speedup()
{
    if(r_> 1.0f* playerInitSize)
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
