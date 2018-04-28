#include <iostream>
#include <random>     //random numbers
#include <functional> //std::bind

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>

#include "Ball.hpp"
#include "Const.hpp"




int main(int argc, char const *argv[]) {

///TODO: Food class, movement, deleting & creating new

    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()

    std::random_device rd2;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen2(rd2());

    std::uniform_real_distribution<> dis_w(1,99);
    // std::uniform_real_distribution<> dis_h(10, windowHeight-10);
    std::uniform_real_distribution<> dis_ball(2, 98);
    std::uniform_int_distribution<> col(minColor,maxColor);
    auto rnd_pos = std::bind(dis_w, gen);
    // auto rnd_h = std::bind(dis_h, gen2);
    auto rnd_ball = std::bind(dis_ball,gen);
    auto rnd_col = std::bind(col,gen);

    sf::ContextSettings contextSettings_;
    contextSettings_.depthBits = 32;

    sf::RenderWindow window(sf::VideoMode(windowWidth,windowHeight), "Agar.io", sf::Style::Default, contextSettings_);


  Ball pilka(rnd_ball()*window.getSize().x/100,rnd_ball()*window.getSize().y/100,playerInitSize,0,0,255);
  pilka.makeFancy();


    // Generowanie spamu
    std::vector<Ball> spam;
    for(int i=0; i<maxFood ;i++)
    {
      Ball food(rnd_pos(),rnd_pos(),5,rnd_col(),rnd_col(),rnd_col());
      spam.push_back(food);
    }




  window.setActive();

  while(window.isOpen())
  {
    sf::Event event;
    while(window.pollEvent(event))
    {
      if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
        window.close();
      if (event.type == sf::Event::Resized)
      {
        window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
      }
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear(sf::Color(2,2,2));
    for(auto& spam_ : spam) spam_.update(window);
    for(auto& spam_ : spam) window.draw(spam_.get());
    window.draw(pilka.get());
    window.display();
  }


  return 0;
}
