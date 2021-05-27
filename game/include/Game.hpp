#ifndef GAME_GAME_HPP
#define GAME_GAME_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "../include/GameDesign.hpp"
class Game
{
  private:
    GameDesign game;
    sf::Event _event;

  public:
    /*!
     * Function through a loop pops the event on top of the event queue
     */
    void pollEvents();

    /*!
     * Function update event
     */
    void update();
    const bool running() const;
    void render();
};

#endif // GAME_GAME_HPP
