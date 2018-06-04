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
    // auto v = velocity;
    //
    // if (r_ > 1.005*playerInitSize)
    // {
    //     r_ /= 1.005;
    //     velocity = 4(r_-playerInitSize)*velocity;
    // }
    // velocity = v;
    if(r_> 2* playerInitSize)
    {
        // auto v = velocity;
        velocity = std::min(2*velocity,5*velocity_factor/playerInitSize);
        r_ /= 1.005;
    }
}

Gamer::~Gamer() {}
