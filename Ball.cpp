#include "Ball.hpp"

 Ball::Ball (float x_, float y_, float r_, int red, int green, int blue)
 {
   shape_.setPosition(x_, y_);
   shape_.setRadius(r_);
   shape_.setFillColor(sf::Color(red,green,blue));
   shape_.setOrigin(r_, r_);
 }

 sf::CircleShape Ball::get()
{
  return shape_;
}
void Ball::makeFancy()
{
  shape_.setOutlineColor(sf::Color::White);
  shape_.setOutlineThickness(-shape_.getRadius()/20);
}
 Ball::~Ball(){}
