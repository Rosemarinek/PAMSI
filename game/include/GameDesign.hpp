#ifndef GAME_GAMEDESIGN_HPP
#define GAME_GAMEDESIGN_HPP

#include "Menu.hpp"
#include "MainBoard.hpp"
#include "Player.hpp"

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
    int _size=0;

    /*vectors storing board coordinates*/
    std::vector<float> _xCor;
    std::vector<float> _yCor;

    /*Menu objects*/
    Menu menu;
    /* X and 0 objects */
    Player player;
    /*Board objects */
    MainBoard board;

    std::vector<sf::Sprite> _setX;
    std::vector<sf::Sprite> _setO;
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
     * Function clears window
     */
    void clearWindow();
    /*
     * Function draws the board
     */
    void drawBoard();
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
    /*!
     * Function draws the selection menu
     */
    void drawChoice();
    /*!
     * Function draws possible board sizes
     */
    void drawSize();
    /*!
     * Function draws the number of wing characters
     */
    void drawWinNumber();
    /*!
     * Function draws play button
     * @param x - button x coordinate
     * @param y - button y coordinate
     */
    void drawPlayButton(float x, float y);
};

#endif // GAME_GAMEDESIGN_HPP
