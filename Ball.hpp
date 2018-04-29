#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>

#include "Const.hpp"

class Ball {
public:
  sf::CircleShape shape_;
  float x_coeff, y_coeff, r_;
  Ball (float , float , float, int, int, int );
  //sf::CircleShape get(); //public access to shape_

 void update(sf::RenderWindow &window);
 void settingPosition(sf::RenderWindow &window);


  // virtual void update() = 0;
  virtual ~Ball () = 0;
};
