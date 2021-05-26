#ifndef GAME_GAME_HPP
#define GAME_GAME_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Game
{
  private:
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event event;

    sf::RectangleShape shape;

    // Mouse position relative to window
    sf::Vector2i mousePosWindow;

    float _height = 800;
    float _width = 600;

    // logo objects
    sf::Image imLogo;
    sf::Texture texLogo;
    sf::Sprite logo;

    // x
    sf::Image imX;
    sf::Texture texX;
    sf::Sprite x;

    // o
    sf::Image imO;
    sf::Texture texO;
    sf::Sprite o;

    //board
    sf::Image imBoard;
    sf::Texture texBoard;
    sf::Sprite board;
    std::vector<sf::Sprite> _boards;



    void initVariable();
    void initWindow();
    void initShape();


  public:
    Game();
    //    virtual ~Game();
    ~Game();

    const bool running() const;
    void update();
    void render();
    void pollEvents();
    void updateMousePos();



    void initLogo();
    void initX(float x, float y);
    void initO(float x, float y);
    void initBoard(float x, float y, float size);
    void drawBoard(int size);

};

#endif // GAME_GAME_HPP
