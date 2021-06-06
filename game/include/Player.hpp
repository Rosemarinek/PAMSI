#ifndef GAME_PLAYER_HPP
#define GAME_PLAYER_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Player
{
  public:
    /* X objects */
    sf::Image _imX;
    sf::Texture _texX;
    sf::Sprite _x;

    /* O objects */
    sf::Image _imO;
    sf::Texture _texO;
    sf::Sprite _o;

    /*
     * Function loads the file with X texture and initializes it. Takes the coordinates indicating where to put
     * X
     * @param x - x coordinate
     * @param y - y coordinate
     * @param size - board size
     */
    void initX(float x, float y, int size);
    /*
     * Function loads the file with O texture and initializes it. Takes the coordinates indicating where to put
     * O
     * @param x - x coordinate
     * @param y - y coordinate
     * @param size - board size
     */
    void initO(float x, float y, int size);
};

#endif // GAME_PLAYER_HPP
