#ifndef GAME_GAME_HPP
#define GAME_GAME_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "GameDesign.hpp"
#include "MinMax.hpp"

/*!
 * Class Game is responsible for game events
 */
class Game
{
  private:
    GameDesign gameDesign;
    sf::Event _event;


    MinMax* minMaxGame;
    /*Variable specifying the current appearance of the game */
    int _gameStatus;
    /* Variable specifying the number of winning characters*/
    int _winNumber;
    /*vector storing the position of x*/
    std::vector<sf::Sprite> _doneCharX;
    /*vector storing the position of o*/
    std::vector<sf::Sprite> _doneCharO;
    /*matrix with slot numbers*/
    std::vector<std::vector<int>> _slot;
    /*Variable specifying if computer moves first*/
    bool isFirstMove;
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
     * Function changes color of the play button when the mouse cursor is on it
     * @param event - argument defines a system event
     */
    void onPlay(const sf::Event& event);
    /*!
     * Function checks if the mouse cursor is on game element depending on the game state
     * @param event - argument defines a system event
     */
    void checkMouseStatus(const sf::Event& event);
    /*!
     *Function checks where and when the mouse button was clicked
     * @param event - argument defines a system event
     */
    void checkClickStatus(const sf::Event& event);
    /*!
     *Function draw appropriate game elements depending on the game state
     */
    void checkGameStatus();
    /*!
     * Function changes color of the size number when the mouse cursor is on it
     * @param event - argument defines a system event
     */
    void onSize(const sf::Event& event);
    /*!
     *Function changes the color of the number indicating the number of characters needed to win when the mouse cursor
     *is on it
     * @param event - argument defines a system event
     */
    void onNumber(const sf::Event& event);
    /*!
     * Function changes color of the X when the mouse cursor is on it
     * @param event - argument defines a system event
     */
    void onX(const sf::Event& event);
    /*!
     * Function changes color of the O when the mouse cursor is on it
     * @param event - argument defines a system event
     */
    void onO(const sf::Event& event);
    /*!
     * Function changes color of the back button when the mouse cursor is on it
     * @param event - argument defines a system event
     */
    void onBack(const sf::Event& event);
    /*!
     * Function changes color of the reset button when the mouse cursor is on it
     * @param event - argument defines a system event
     */
    void onRestart(const sf::Event& event);
    /*!
     * Function checks if the sprite object has been pressed
     * @param event - argument defines a system event
     * @param sprite - sprite object.
     * @return true if the object has been pressed or false if the object hasn't been pressed
     */
    static bool elementPressed(const sf::Event& event, const sf::Sprite& sprite);
    /*!
     * Function checks if the text object has been pressed
     * @param event - argument defines a system event
     * @param text - text object.
     * @return true if the object has been pressed or false if the object hasn't been pressed
     */
    static bool elementPressed(const sf::Event& event, const sf::Text& text);
    /*!
     * Function that moves player to the selected slot*
     * @param slot - selected slot
     */
    void movePlayer(int slot);
    /*!
     * Function that moves AI
     */
    void moveAI();
    /*!
     * Function resets the game
     */
    void restart();
    /*!
     * Function takes the player back to the menu
     */
    void back();
    /*!
     * Function checks if someone has won
     */
    void isEnd();
    /*!
     * Function creates matrix with slot numbers depending on the game size
     */
    void initSlot();
    /*!
     * Function converts the slot into row and column
     */
    Move slotCor(int slot);
    /*Constructor and destructor*/
    Game();
    ~Game();
};

#endif // GAME_GAME_HPP
