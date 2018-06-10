#include "Game.hpp"
/**
*   /brief
*   The main function of a game
*/
void Game::init(sf::RenderWindow &window)
{
    /**
    *   Random number generators for generating position, color and ball restoration
    */
    std::random_device rd;
    std::mt19937 gen(rd());
    std::random_device rd2;
    std::mt19937 gen2(rd2());
    std::uniform_real_distribution<> dis_w(1,99);
    std::uniform_int_distribution<> col(minColor,maxColor);
    auto rnd_pos = std::bind(dis_w, gen); /**< position generator */
    auto rnd_col = std::bind(col,gen); /**< color generator */

    std::random_device rd3;
    std::uniform_int_distribution<int> int_distribution(1, 100);
    std::mt19937 ballGen(rd3());

    /**
    *   Player and Bot initialisation
    */
    Gamer pilka(48,48,playerInitSize,0,0,255);
    pilka.settingPosition(window);
    Bot bot(rnd_pos(),rnd_pos(), playerInitSize, 0, 255, 0);
    bot.settingPosition(window);

    window.setActive();

    /**
    *   Loop for defining spikes positions
    */
    for (int i=0; i<numspikes; ++i)
    {
        Spike spike(rnd_pos(),rnd_pos(), spikesSize, 255,255,0);
        spikes.insert(spikes.end(), spike);
    }

    /**
    *   Necessary update with comming from menu to game window
    */
    for(auto& spike_ : spikes)
    {
       spike_.settingPosition(window);
       spike_.update(window);
    }

    /**
    *   Loop for defining food positions
    */
    for(int i=0; i<=maxFood ;++i)
    {
       Food food(rnd_pos(),rnd_pos(),5,rnd_col(),rnd_col(),rnd_col());
       spam.insert(spam.end(), food);
    }

    /**
    *   Necessary update with comming from menu to game window
    */
   for(auto& spam_ : spam)
   {
       spam_.settingPosition(window);
       spam_.update(window);
   }

   sf::Clock food_clock; /**< Timer for food regeneration */

   while(window.isOpen())
   {
        sf::Event event;
        currentWindowX = window.getSize().x;
        currentWindowY = window.getSize().y;
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

                pilka.resettingPosition(window, pilka.returnPosition().x/currentWindowX, pilka.returnPosition().y/currentWindowY);
                pilka.update(window);

                bot.resettingPosition(window, bot.returnPosition().x/currentWindowX, bot.returnPosition().y/currentWindowY);
                bot.update(window);


                 for(auto& spike_ : spikes)
                {
                    spike_.settingPosition(window);
                    spike_.update(window);
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

        /**
        *   Interacting with spikes
        */
        for(auto& spike_ : spikes)
        {

            if (pilka.intersect(spike_, spikesDifference) && pilka.returnRadius() > playerInitSize) pilka.r_ -= 1;
            if (bot.intersect(spike_, spikesDifference) && bot.returnRadius() > playerInitSize) bot.r_ -= 1;

        };

        /**
        *   Interacting with food
        */
        spam.erase(std::remove_if(spam.begin(), spam.end(), [&pilka, &bot](Food f){ return pilka.intersect(f, eatingDifference) || bot.intersect(f, eatingDifference);}), spam.end());

        /**
        *   Food regeneration
        */
        spamsize = static_cast<int>(spam.size());
        if (spamsize < maxFood && food_clock.getElapsedTime().asMilliseconds() > food_time)
        {
            food_clock.restart();
            if(int_distribution(ballGen) < (static_cast<int>(100*(maxFood - spamsize)/maxFood)+10))
            {
                Food food(rnd_pos(),rnd_pos(),5,rnd_col(),rnd_col(),rnd_col());
                spam.insert(spam.end(),food);
                spam.back().settingPosition(window);
                spam.back().update(window);
            }
        }

        for(const auto& spam_ : spam) window.draw(spam_.shape_); /**< Drawing food in window */

        /**
        *   Winning/losing conditions check
        */
        if (pilka.intersect(bot, eatingDifference))
        {
            if(pilka.returnRadius() > bot.returnRadius())
            {
                std::cout << "You've won the game" << '\n';
                window.close();
            }
            else if (bot.returnRadius() > pilka.returnRadius())
            {
                std::cout << "You've failed!" << '\n';
                window.close();
            }
        }

        /**
        *   A condition needed for a bigger ball to be drawn over smaller
        */
        if(pilka.returnRadius() >= bot.returnRadius())
        {
            window.draw(bot.shape_);
            window.draw(pilka.shape_);
        }
        else
        {
            window.draw(pilka.shape_);
            window.draw(bot.shape_);
        }

        for(const auto& spike_ : spikes) window.draw(spike_.shape_); /**< Drawing spikes */

        pilka.update(window); /**< Updating player's ball radius and transform origin */
        pilka.movement(window); /**< Player's ball movement */

        bot.update(window); /**< Updating player's ball radius and transform origin */
        bot.movement(window, pilka, spam); /** Bot's ball movement */

        window.display(); /**< Show actual frame of game */
    }
}
Game::Game(){}
Game::~Game(){}
