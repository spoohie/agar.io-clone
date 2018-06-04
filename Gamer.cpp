#include "Gamer.hpp"

Gamer::Gamer(float x, float y, float r, int red, int green, int blue) : Player(x, y, r, red, green, blue) {}

void Gamer::movement(sf::RenderWindow& window)
{
    mouse_pos = sf::Mouse::getPosition(window);
    //std::cout << shape_.getPosition().x << "    " << shape_.getPosition().y << std::endl ;

    //std::cout << shape_.getPosition().x<< std::endl ;
    //poprawić
    //shape_.move(velocity*(mouse_pos.x - shape_.getPosition().x),velocity*(mouse_pos.y - shape_.getPosition().y));
    float diff_x = static_cast<float>(mouse_pos.x) - shape_.getPosition().x;
    float diff_y = static_cast<float>(mouse_pos.y) - shape_.getPosition().y;
    shape_.move(velocity*diff_x,velocity*diff_y);
}

void Gamer::speedup()
{
    if(r_> 2.0f* playerInitSize)
    {
        velocity = std::min(2.0f*velocity,velocity_factor/playerInitSize);
        r_ /= 1.01f;
    } else velocity = velocity_factor/r_;
}

void Gamer::defaultSpeed()
{
    velocity = velocity_factor/r_;
}

Gamer::~Gamer() {}
