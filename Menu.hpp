/**
*   \class Menu
*   \brief A menu class representing menu and arrow-based moving on it.
*/
#pragma once
#include "SFML/Graphics.hpp"
#include "Const.hpp"

class Menu {
private:
    int select; /**< a integer number of selected option. */
    sf::Font font;  /**< a SFML member of defining font style (here Arial).*/
    sf::Text menu[numberOfMenuItems]; /**< Contains menu elements. */

public:
    Menu (float, float);
    ~Menu ();

    void draw(sf::RenderWindow&);
    void moveUp();
    void moveDown();
    int getItem();
};
