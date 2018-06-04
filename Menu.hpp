#pragma once
#include "SFML/Graphics.hpp"

#define NUMOFITEMS 3

class Menu {
private:
    int select;
    sf::Font font;
    sf::Text menu[NUMOFITEMS];

public:
    Menu (float, float);
    ~Menu ();

    void draw(sf::RenderWindow& /*&window*/);
    void moveUp();
    void moveDown();
    int getItem();
};
