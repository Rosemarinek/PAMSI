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
    sf::VideoMode _videoMode;
    sf::RenderWindow* _window;

    /*window dimensions*/
    float _height;
    float _width;

    /*the coordinates of the drawing location*/
    const float _firstX = 50;
    const float _firstY = 200;

    /*board size*/
    int _size = 3;

    //    sf::String playerInput;
//    sf::Text playerText;

    /*vectors storing board coordinates*/
    std::vector<float> _xCor;
    std::vector<float> _yCor;


    /*Menu objects*/
    sf::Image _imMenu;
    sf::Texture _texMenu;
    sf::Sprite _menu;

    /*Font object*/
    sf::Font _font;
    std::vector<sf::Text> _text;

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
    void initVariable(float width,float height);
    /*!
     * Function is responsible for window initialization
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
    /*!
     * Function initializes start menu
     */
    void initMenu();
    /*!
     * Functions draws start menu
     */
    void drawMenu();
    /*!
     * Function draws X on the selected location
     * @param x - x coordinate
     * @param y - y coordinate
     */
    void drawX(float x, float y);
    /*!
      * Function draws O on the selected location
      * @param x - x coordinate
      * @param y - y coordinate
      */
    void drawO(float x, float y);
};

#endif // GAME_GAMEDESIGN_HPP
