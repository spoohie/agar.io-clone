#include "Ball.hpp"
#include <cmath>

 Ball::Ball (float x, float y, float r, int red, int green, int blue)
 {
   x_coeff = x/100;
   y_coeff = y/100;
   r_ = r;
   shape_.setFillColor(sf::Color(red,green,blue));
 }


void Ball::update(sf::RenderWindow &window)
{
  shape_.setPosition(x_coeff*window.getSize().x, y_coeff*window.getSize().y);
  shape_.setRadius(r_);

  shape_.setOrigin(r_, r_);
}


 Ball::~Ball(){}
