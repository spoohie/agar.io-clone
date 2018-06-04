#include "Game.hpp"
#include "Menu.hpp"
int main(int argc, char const *argv[])
{
    sf::ContextSettings contextSettings_;
    sf::RenderWindow window(sf::VideoMode(windowWidth,windowHeight), "Agar.io", sf::Style::Default, contextSettings_);
    contextSettings_.depthBits = 32;

    Game game;

    Menu menu(windowWidth, windowHeight);
    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::KeyReleased)
            {
                auto key = event.key.code;
                switch (key)
				{
				case sf::Keyboard::Up:
					menu.moveUp();
					break;

				case sf::Keyboard::Down:
					menu.moveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.getItem())
					{
					case 0:
						std::cout << "Play button has been pressed" << std::endl;
                        game.init(window);
						break;
					case 1:
						std::cout << "Option button has been pressed" << std::endl;
						break;
					case 2:
						window.close();
						break;
                    default:
                        break;
                    }
                    break;
                default:
                    break;
				}
            }
            if(event.type == sf::Event::Closed)
                window.close();
        }
    		window.clear();
    		menu.draw(window);
    		window.display();
    }
    return 0;
}
