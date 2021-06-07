#ifndef GAME_MAINBOARD_HPP
#define GAME_MAINBOARD_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

/*!
 * Structures is responsible for the main game board
 */
struct MainBoard
{
    /* Game logo objects */
    sf::Image _imLogo;
    sf::Texture _texLogo;
    sf::Sprite _logo;

    /*Game board objects*/
    sf::Image _imBoard;
    sf::Texture _texBoard;
    sf::Sprite _board;
    std::vector<sf::Sprite> _boards;

    sf::Image _imBack;
    sf::Texture _texBack;
    sf::Sprite _back;

    sf::Image _imRestart;
    sf::Texture _texRestart;
    sf::Sprite _restart;

    sf::Font _font;
    sf::Text _text;

    /*!
     * Function loads the file with logo texture and initializes it
     * @param width - window width
     */
    void initLogo(float width);
    /*!
     * Function loads the file with board texture and initializes it. Takes the coordinates indicating where to put
     * board
     * @param x - x coordinate
     * @param y - y coordinate
     * @param size - board size
     */
    void initBoard(float x, float y, int size);
    /*!
     * Function loads the file with back button texture and initializes it. Takes the coordinates indicating where to
     * put the button
     * @param x - x coordinate
     * @param y - y coordinate
     * @param scale - argument needed to scale the button
     */
    void initBack(float x, float y, float scale);
    /*!
     * Function loads the file with restart button texture and initializes it. Takes the coordinates indicating where to
     * put the button
     * @param x - x coordinate
     * @param y - y coordinate
     * @param scale - argument needed to scale the button
     */
    void initRestart(float x, float y, float scale);
    /*!
      * Function loads the file with font and initializes text. Takes the coordinates indicating where to put
      * the text
      * @param x - x coordinate
      * @param y - y coordinate
      * @param text - the text the function is to draw
      */
    void initText(float x, float y, std::string text);
};

#endif // GAME_MAINBOARD_HPP
