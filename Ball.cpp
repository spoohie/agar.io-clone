#include "Ball.hpp"

/** A Bot class constructor
*   @param x a float percentage number that defines horizontal position
*   @param y a float percentage number that defines vertical position
*   @param r a float number representing radius of a balls
*   @param red a integer number representing red color in RGB
*   @param green a integer number representing green color in RGB
*   @param blue a integer number representing blue color in RGB
*/
Ball::Ball (float x, float y, float r, int red, int green, int blue)
{
    x_coeff = x/100;
    y_coeff = y/100;
    r_ = r;
    shape_.setFillColor(sf::Color(red,green,blue));
}

/** Setting position of a ball at the beginning
*   @param window a SFML window member
*/
void Ball::settingPosition(sf::RenderWindow &window)
{
    shape_.setPosition(x_coeff*window.getSize().x, y_coeff*window.getSize().y);
}

/** Resetting position after scaling the window
*   @param window a SFML window member
*   @param xx current x position at window
*   @param yy current y position at window
*/
void Ball::resettingPosition(sf::RenderWindow &window, float xx, float yy)
{
    shape_.setPosition(xx*window.getSize().x, yy*window.getSize().y);
}

sf::Vector2f Ball::returnPosition()
{
    return shape_.getPosition();
}

int Ball::returnRadius()
{
    return r_;
}

/** Updating ball's radius and transformation origin after calculations
*   @param window a SFML window member
*/
void Ball::update(sf::RenderWindow &window)
{
    shape_.setRadius(r_);
    shape_.setOrigin(r_, r_);
}

Ball::~Ball(){}
