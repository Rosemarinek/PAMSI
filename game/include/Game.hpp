#ifndef GAME_GAME_HPP
#define GAME_GAME_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "../include/GameDesign.hpp"

/*
 * Class Game is responsible for game events
 */
class Game
{
  private:
    GameDesign game;
    sf::Event _event;

    /*variables holding the mouse position*/
    int clickX = 0;
    int clickY = 0;

    /*a variable that determines whose movement it is*/
    int _whoseMove=0;

  public:
    /*!
     * Function through a loop pops the event on top of the event queue
     */
    void pollEvents();
    /*!
     * Function updates event
     */
    void update();
    /*!
     *
     */
    void render();
    /*
     * Function that starts the game
     */
    void run();
    /*
     * Function draws X or O depending on the movement
     */
    void moveXorO();

    /*Constructor and destructor*/
    Game();
    ~Game();
};

#endif // GAME_GAME_HPP
