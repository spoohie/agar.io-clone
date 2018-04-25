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

    std::uniform_real_distribution<> dis_w(10, windowWidth-10);
    std::uniform_real_distribution<> dis_h(10, windowHeight-10);
    std::uniform_real_distribution<> dis_ball(60, windowWidth-60);
    std::uniform_int_distribution<> col(minColor,maxColor);
    auto rnd_w = std::bind(dis_w, gen); // a copy of e is stored in rnd
    auto rnd_h = std::bind(dis_h, gen2);
    auto rnd_ball = std::bind(dis_ball,gen);
    auto rnd_col = std::bind(col,gen);


  Ball pilka(rnd_ball(),rnd_ball(),playerInitSize,0,0,255);
  pilka.makeFancy();


    // Generowanie spamu
    std::vector<Ball> spam;
    for(int i=0; i<maxFood ;i++)
    {
      Ball food(rnd_h(),rnd_w(),5,rnd_col(),rnd_col(),rnd_col());
      spam.push_back(food);
    }



  sf::ContextSettings contextSettings_;
  contextSettings_.depthBits = 32;

  sf::RenderWindow window(sf::VideoMode(windowWidth,windowHeight), "Agar.io", sf::Style::Fullscreen, contextSettings_);

  window.setActive();

  while(window.isOpen())
  {
    sf::Event event;
    while(window.pollEvent(event))
    {
      if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
               window.close();
    }

    window.clear(sf::Color(2,2,2));
    for(auto& spam_ : spam) window.draw(spam_.get());
    window.draw(pilka.get());
    window.display();
  }


  return 0;
}
