#ifndef GAME_GAMEDESIGN_HPP
#define GAME_GAMEDESIGN_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

/*
 * Class Game Design is responsible for the graphic appearance of the game
 */
class GameDesign
{
    friend class Game;

  private:
    /*window dimensions*/
    const float _height = 800;
    const float _width = 600;

    /*the coordinates of the drawing location*/
    const float _firstX = 50;
    const float _firstY = 200;

    /*board size*/
    int _size = 3;

    sf::VideoMode _videoMode;
    sf::RenderWindow* _window;

    /* Game logo objects */
    sf::Image _imLogo;
    sf::Texture _texLogo;
    sf::Sprite _logo;

    /* X objects */
    sf::Image _imX;
    sf::Texture _texX;
    sf::Sprite _x;

    /* O objects */
    sf::Image _imO;
    sf::Texture _texO;
    sf::Sprite _o;

    /* board objects */
    sf::Image _imBoard;
    sf::Texture _texBoard;
    sf::Sprite _board;
    std::vector<sf::Sprite> _boards;

    /*!
     * Function is responsible for initialization of individual variables
     */
    void initVariable();
    /*!
     *
     */
    void initWindow();

  public:
    /*!
     * Constructor and destructor
     */
    GameDesign();
    ~GameDesign();
    /*!
     * Function draws individual elements
     */
    void renderGame();
    /*
     * Function loads the file with logo texture and initializes it
     */
    void initLogo();
    /*
     * Function loads the file with X texture and initializes it. Takes the coordinates indicating where to put
     * X
     * @param x - x coordinate
     * @param y - y coordinate
     */
    void initX(float x, float y);
    /*
     * Function loads the file with O texture and initializes it. Takes the coordinates indicating where to put
     * O
     * @param x - x coordinate
     * @param y - y coordinate
     */
    void initO(float x, float y);
    /*
     * Function loads the file with board texture and initializes it. Takes the coordinates indicating where to put
     * board
     * @param x - x coordinate
     * @param y - y coordinate
     */
    void initBoard(float x, float y);
    /*
     * Function draws the board
     */
    void drawBoard();
};

#endif // GAME_GAMEDESIGN_HPP
