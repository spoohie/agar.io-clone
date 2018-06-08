#include "Bot.hpp"

Bot::Bot(float x, float y, float r, int red, int green, int blue) : Player(x, y, r, red, green, blue) {}

void Bot::movement(sf::RenderWindow& window, sf::Vector2f& playerPosition)
{
    float diff_x = static_cast<float>(playerPosition.x) - shape_.getPosition().x;
    float diff_y = static_cast<float>(playerPosition.y) - shape_.getPosition().y;
    if(sqrt(pow(diff_x, 2.0)+pow(diff_y, 2.0)) > 100.0)
    {
        shape_.move(velocity*diff_x*0.8,velocity*diff_y*0.8);
    } else shape_.move(velocity*diff_x,velocity*diff_y);




    /*mouse_pos = sf::Mouse::getPosition(window);
    float diff_x = static_cast<float>(mouse_pos.x) - shape_.getPosition().x;
    float diff_y = static_cast<float>(mouse_pos.y) - shape_.getPosition().y;
    if(sqrt(pow(diff_x, 2.0)+pow(diff_y, 2.0)) > 100.0)
    {
        shape_.move(velocity*diff_x*0.5,velocity*diff_y*0.5);
    } else shape_.move(velocity*diff_x,velocity*diff_y);*/
}


Bot::~Bot() {}
