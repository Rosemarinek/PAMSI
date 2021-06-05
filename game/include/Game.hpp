#ifndef GAME_GAME_HPP
#define GAME_GAME_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "GameDesign.hpp"
#include "MinMax.hpp"

/*
 * Class Game is responsible for game events
 */
class Game
{
  private:
    GameDesign gameDesign;
    sf::Event _event;

    MinMax *minMaxGame;

    /*Variable specifying the current appearance of the game */
    int _gameStatus;
    /* Variable specifying the number of winning characters*/
    int _winNumber;
    /*variable specifying whose movement is*/
    int _whoseMove;

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
    void onPlay(const sf::Event& event);
    /*!
     * Function checks if the mouse cursor is on game element depending on the game state
     */
    void checkMouseStatus(const sf::Event& event);
    /*!
     *Function checks where and when the mouse button was clicked
     */
    void checkClickStatus(const sf::Event& event);
    /*!
     *Function draw appropriate game elements depending on the game state
     */
    void checkGameStatus();
    /*!
     * Function changes color of the size number when the mouse cursor is on it
     */
    void onSize(const sf::Event& event);
    /*!
     *Function changes the color of the number indicating the number of characters needed to win when the mouse cursor
     *is on it
     */
    void onNumber(const sf::Event& event);

    /*Constructor and destructor*/
    Game();
    //~Game();
    static bool elementPressed(const sf::Event& event, const sf::Sprite& sprite);
    static bool elementPressed(const sf::Event& event, const sf::Text& text);
    void movePlayer(int row,int column, int slot);
};

#endif // GAME_GAME_HPP
