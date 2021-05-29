#include "../include/GameDesign.hpp"
#include <iostream>

void GameDesign::initVariable(float width, float height)
{
    _window = nullptr;
    _width = width;
    _height = height;
}

void GameDesign::initWindow()
{
    _videoMode = sf::VideoMode(_width, _height);
    _window = new sf::RenderWindow(_videoMode, "Tic Tac Toe", sf::Style::Close | sf::Style::Titlebar);
    _window->setFramerateLimit(60);
    _window->setVerticalSyncEnabled(false);
}

GameDesign::GameDesign()
{
    initVariable(600, 800);
    initWindow();
    initLogo();
    initMenu();
}

GameDesign::~GameDesign()
{
    delete _window;
}

void GameDesign::renderGame()
{
    _window->clear(sf::Color(98, 175, 255));
    //drawMenu();
    drawBoard();
    _window->draw(_logo);
}

void GameDesign::initLogo()
{
    _imLogo.loadFromFile("../resources/textures/logo.png");
    _texLogo.loadFromImage(_imLogo);
    _texLogo.setSmooth(true);
    _logo.setTexture(_texLogo);

    auto scale = static_cast<float>(_width / _imLogo.getSize().x);
    _logo.setScale(sf::Vector2f(scale, scale));
    _logo.setOrigin(sf::Vector2f(10.f, 25.f));
}

void GameDesign::initX(float x, float y)
{
    float scale = 1.f - (static_cast<float>(_size - 3)) * 0.15f;
    _imX.loadFromFile("../resources/textures/x.png");
    _texX.loadFromImage(_imX);
    _texX.setSmooth(true);
    _x.setTexture(_texX);
    _x.setScale(sf::Vector2f(scale, scale));
    _x.setPosition(x, y);
}

void GameDesign::initO(float x, float y)
{
    float scale = 1.f - (static_cast<float>(_size - 3)) * 0.15f;
    _imO.loadFromFile("../resources/textures/o.png");
    _texO.loadFromImage(_imO);
    _texO.setSmooth(true);
    _o.setTexture(_texO);
    _o.setScale(sf::Vector2f(scale, scale));
    _o.setPosition(x, y);
}

void GameDesign::initBoard(float x, float y)
{
    float scale = 1.f - (static_cast<float>(_size - 3)) * 0.15f;
    _imBoard.loadFromFile("../resources/textures/board.png");
    _texBoard.loadFromImage(_imBoard);
    _texBoard.setSmooth(true);
    _board.setTexture(_texBoard);
    _board.setScale(sf::Vector2f(scale, scale));
    _board.setPosition(x, y);
}

void GameDesign::drawBoard()
{
    _boards.resize(_size);
    _xCor.resize(_size);
    _yCor.resize(_size);


    float w = (_width - 100) / (static_cast<float>(_size));
    float h = (_height - 300) / (static_cast<float>(_size));
    for(auto i = 0; i < _size; ++i)
    {
        for(auto j = 0; j < _size; j++)
        {
            _xCor[i]=_firstX + i * w;
            _yCor[j]=_firstY + j * h;
            initBoard(_xCor[i], _yCor[j]);
            _boards.push_back(_board);
        }
    }

    for(auto& i : _boards)
    {
        _window->draw(i);
    }
}

void GameDesign::initMenu()
{
    _imMenu.loadFromFile("../resources/textures/menu.png");
    _texMenu.loadFromImage(_imMenu);
    _texMenu.setSmooth(true);
    _menu.setTexture(_texMenu);
    _menu.setScale(sf::Vector2f(1.f, 1.f));
    _menu.setPosition(0, 0);

    _text.resize(3);
    _font.loadFromFile("../resources/fonts/Gabi.ttf");

    _text[0].setFont(_font);
    _text[0].setFillColor(sf::Color::White);
    _text[0].setString("START");
    _text[0].setPosition(sf::Vector2f(_width / 3.5, _height / 3));
    _text[0].setCharacterSize(100);

    //    _text[1].setFont(_font);
    //    _text[1].setFillColor(sf::Color::White);
    //    _text[1].setString("Choose size");
    //    _text[1].setPosition(sf::Vector2f(_width/4,_height/2));
    //    _text[1].setCharacterSize(50);

    _text[1].setFont(_font);
    _text[1].setFillColor(sf::Color::White);
    _text[1].setString("Press ESC to EXIT");
    _text[1].setPosition(sf::Vector2f(_width / 4, _height / 1.5));
    _text[1].setCharacterSize(50);
}

void ::GameDesign::drawMenu()
{
    _window->clear(sf::Color(98, 175, 255));
    _window->draw(_menu);
    for(int i = 0; i < _text.size(); ++i)
    {
        _window->draw(_text[i]);
    }
}

void GameDesign::drawO(float x, float y)
{
    initX(x,y);
    _window->draw(_x);
}

void GameDesign::drawX(float x, float y)
{
    initO(x,y);
    _window->draw(_o);
}
