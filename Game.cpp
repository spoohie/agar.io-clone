#include "Game.hpp"

void Game::init(sf::RenderWindow &window)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::random_device rd2;
    std::mt19937 gen2(rd2());

    std::uniform_real_distribution<> dis_w(1,99);
    std::uniform_real_distribution<> dis_ball(2, 98);
    std::uniform_int_distribution<> col(minColor,maxColor);
    auto rnd_pos = std::bind(dis_w, gen); //foods' position generator
    auto rnd_ball = std::bind(dis_ball,gen); //player's position generator
    auto rnd_col = std::bind(col,gen); //color generator

    std::random_device rd3;
    std::uniform_int_distribution<int> int_distribution(1, 100);
    std::mt19937 prob_eng(rd3());



    //initialize player
    Gamer pilka(rnd_ball(),rnd_ball(),playerInitSize,0,0,255);
    pilka.settingPosition(window);

    window.setActive();
    
    // food generating
    for(int i=0; i<=maxFood ;++i)
    {
       Food food(rnd_pos(),rnd_pos(),5,rnd_col(),rnd_col(),rnd_col());
       spam.push_back(food);
    }

   for(auto& spam_ : spam)
   {
       //necessary while comming from menu
       spam_.settingPosition(window);
       spam_.update(window);
   }

   sf::Clock food_clock;
   //sf::Time food_clock_elapsed = food_clock.getElapsedTime();

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
                pilka.speedup();
            }
            if ((event.type == sf::Event::KeyReleased)&&(event.key.code == sf::Keyboard::Space))
            {
                pilka.defaultSpeed();
            }

        }

      //there are all of the mysteries (loop based)
        window.clear(sf::Color(2,2,2));

        spam.erase(std::remove_if(spam.begin(), spam.end(), [&pilka](Food f){ return pilka.intersect(f);}), spam.end());
        
        spamsize = static_cast<int>(spam.size());
        
        if (spamsize < maxFood && food_clock.getElapsedTime().asMilliseconds() > food_time)
        {
            food_clock.restart();
            if(int_distribution(prob_eng) < (static_cast<int>(100*(maxFood - spamsize)/maxFood)+10))
            {
                Food food(rnd_pos(),rnd_pos(),5,rnd_col(),rnd_col(),rnd_col());
                spam.push_back(food);
                spam.back().settingPosition(window);
                spam.back().update(window);
            }
        }

        //std::cout << "chuj: " << static_cast<int>(100*(maxFood - spamsize)/maxFood) << ", spam size: " <<spamsize << ", max size: " << maxFood << ", time elapsed: "<< std::endl;

        for(auto& spam_ : spam) window.draw(spam_.shape_);

        window.draw(pilka.shape_);

        pilka.update(window);

        pilka.movement(window);

        window.display();
    }
}
Game::Game(){}
Game::~Game(){}
