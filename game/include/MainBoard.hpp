#ifndef GAME_MAINBOARD_HPP
#define GAME_MAINBOARD_HPP
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class MainBoard
{
  public:
    /* Game logo objects */
    sf::Image _imLogo;
    sf::Texture _texLogo;
    sf::Sprite _logo;

    /*Game board objects*/
    sf::Image _imBoard;
    sf::Texture _texBoard;
    sf::Sprite _board;
    std::vector<sf::Sprite> _boards;

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
};

#endif // GAME_MAINBOARD_HPP
