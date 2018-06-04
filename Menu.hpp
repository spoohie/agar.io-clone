#pragma once
#include "SFML/Graphics.hpp"
#include "Const.hpp"

class Menu {
private:
    int select;
    sf::Font font;
    sf::Text menu[numberOfMenuItems];

public:
    Menu (float, float);
    ~Menu ();

    void draw(sf::RenderWindow&);
    void moveUp();
    void moveDown();
    int getItem();
};
