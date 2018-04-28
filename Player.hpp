#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include "Ball.hpp"

class Player : public Ball {
public:
  Player (float , float , float, int, int, int );
  ~Player ();
};
