#include "Menu.hpp"


Menu::Menu(float width, float height)
{
    if (!font.loadFromFile("arial.ttf"))
    {}



	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (numberOfMenuItems + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Options");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (numberOfMenuItems + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width / 2, height / (numberOfMenuItems + 1) * 3));

	select = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < numberOfMenuItems; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::moveUp()
{
	if (select - 1 >= 0)
	{
		menu[select].setFillColor(sf::Color::White);
		select--;
		menu[select].setFillColor(sf::Color::Red);
	}
}

void Menu::moveDown()
{
	if (select + 1 < numberOfMenuItems)
	{
		menu[select].setFillColor(sf::Color::White);
		select++;
		menu[select].setFillColor(sf::Color::Red);
	}
}

int Menu::getItem()
{
    return select;
}
