#include "Game.hpp"

Game::Game()
{
    // ta część zostanie przeniesiona do osobnego pliku, tak aby wykonywała się tylko raz
    std::random_device rd;    //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()

    std::random_device rd2;    //Will be used to obtain a seed for the random number engine
    std::mt19937 gen2(rd2());

    std::uniform_real_distribution<> dis_w(1,99);
    // std::uniform_real_distribution<> dis_h(10, windowHeight-10);
    std::uniform_real_distribution<> dis_ball(2, 98);
    std::uniform_int_distribution<> col(minColor,maxColor);
    auto rnd_pos = std::bind(dis_w, gen);
    // auto rnd_h = std::bind(dis_h, gen2);
    auto rnd_ball = std::bind(dis_ball,gen);
    auto rnd_col = std::bind(col,gen);



    sf::RenderWindow window(sf::VideoMode(windowWidth,windowHeight), "Agar.io", sf::Style::Default, contextSettings_);
    contextSettings_.depthBits = 32;
    Gamer pilka(rnd_ball(),rnd_ball(),playerInitSize,0,0,255);
    pilka.settingPosition(window);


    // Generowanie spamu
    for(int i=0; i<=maxFood ;++i)
    {
       Food food(rnd_pos(),rnd_pos(),5,rnd_col(),rnd_col(),rnd_col());
       spam.push_back(food);
    }




    window.setActive();

       //sf::Mouse::setPosition(sf::Vector2i(windowWidth/2, windowHeight/2), window);

   while(window.isOpen())
   {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                window.close();

            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::Resized)
            {
                window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
                for(auto& spam_ : spam)
                {
                    spam_.settingPosition(window);
                    spam_.update(window);
                }
            }

            if ((event.type == sf::Event::KeyPressed)&&(event.key.code == sf::Keyboard::Space))
            {
                // sf::Clock clk;
                // while(clk.getElapsedTime().asSeconds() < 10)
                    pilka.speedup();
            }

          // if ((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Right))
          //     for(auto& spam_ : spam) spam_.update(window);

        }
      //TUTAJ RYSUJE SIE WSZYSTKO
        window.clear(sf::Color(2,2,2));
        spam.erase(std::remove_if(spam.begin(), spam.end(), [&pilka](Food f){ return pilka.intersect(f);}), spam.end());
        for(auto& spam_ : spam) window.draw(spam_.shape_);
        window.draw(pilka.shape_);
        pilka.update(window);
        pilka.movement(window);
        window.display();
    }
}

Game::~Game(){}
