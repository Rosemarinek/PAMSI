#ifndef GAME_GAME_HPP
#define GAME_GAME_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "GameDesign.hpp"

/*
 * Class Game is responsible for game events
 */
class Game
{
  private:
    GameDesign game;
    sf::Event _event;
    int _gameStatus=0;

    int winChar=0;

    /*variables holding the mouse position*/
    int clickX = 0;
    int clickY = 0;

    /*variable specifying whose movement is*/
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

    void onPlay(float x, float y);
    void pressPlay(float x, float y);
    void checkGameStatus();
    void checkClickStatus();
    void onSize();
    void onNumber();
    void pressSize();
    void pressNumber();

    /*Constructor and destructor*/
    Game();
    ~Game();
};

#endif // GAME_GAME_HPP
