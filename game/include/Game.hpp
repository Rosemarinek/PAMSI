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

    /*Variable specifying the current appearance of the game */
    int _gameStatus = 0;
    /* Variable specifying the number of winning characters*/
    int _winNumber = 0;
    /*variables for storing the mouse position*/
    int clickX = 0;
    int clickY = 0;
    /*variable specifying whose movement is*/
    int _whoseMove = 0;

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
     * Function that starts the game
     */
    void run();
    /*!
     * Function draws X or O depending on the movement
     */
    void moveXorO();
    /*!
     * Function changes color of the play button when the mouse cursor is on it
     * @param x - button x coordinate
     * @param y - button y coordinate
     */
    void onPlay(float x, float y);
    /*!
     * Function checks if the button has been clicked
     * @param x - button x coordinate
     * @param y - button y coordinate
     */
    void pressPlay(float x, float y);
    /*!
     * Function checks if the mouse cursor is on game element depending on the game state
     */
    void checkMouseStatus();
    /*!
     *Function checks where and when the mouse button was clicked
     */
    void checkClickStatus();
    /*!
     *Function draw appropriate game elements depending on the game state
     */
    void checkGameStatus();
    /*!
     * Function changes color of the size number when the mouse cursor is on it
     */
    void onSize();
    /*!
     *Function changes the color of the number indicating the number of characters needed to win when the mouse cursor
     *is on it
     */
    void onNumber();
    /*!
     * Function checks if the number indicating the size of the board has been clicked
     */
    void pressSize();
    /*!
     * Function checks if the number indicating of characters needed to win has been clicked
     */
    void pressNumber();

    /*Constructor and destructor*/
    Game();
    ~Game();
};

#endif // GAME_GAME_HPP
