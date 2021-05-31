#include "GameDesign.hpp"
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
    board.initLogo(_width);
    menu.initMenu(_width,_height);
    menu.initChoice(_width,_height);
}

GameDesign::~GameDesign()
{
    delete _window;
}

void GameDesign::clearWindow()
{
    _window->clear(sf::Color(98, 175, 255));
}


void GameDesign::drawBoard()
{
    clearWindow();
    board._boards.resize(_size);
    _xCor.resize(_size);
    _yCor.resize(_size);

    float w = (_width - 100) / (static_cast<float>(_size));
    float h = (_height - 300) / (static_cast<float>(_size));
    for(auto i = 0; i < _size; ++i)
    {
        for(auto j = 0; j < _size; j++)
        {
            _xCor[i] = _firstX + i * w;
            _yCor[j] = _firstY + j * h;
            board.initBoard(_xCor[i], _yCor[j], _size);
            board._boards.push_back(board._board);
        }
    }

    for(auto& i : board._boards)
    {
        _window->draw(i);
    }

    _window->draw(board._logo);
}

void ::GameDesign::drawMenu()
{
   clearWindow();
    _window->draw(menu._menu);
    drawPlayButton(_width/3, _height/2.3);
}

void GameDesign::drawO(float x, float y)
{
    player.initX(x, y, _size);
    _window->draw(player._x);
}

void GameDesign::drawX(float x, float y)
{
    player.initO(x, y, _size);
    _window->draw(player._o);
}


void GameDesign::drawChoice()
{
    clearWindow();
    _window->draw(menu._choice);
    for(int i = 0; i < menu._textSize.size(); ++i)
    {
        _window->draw(menu._textSize[i]);
        _window->draw(menu._textNumber[i]);
    }
    drawPlayButton(_width/3,_height/1.7);
}

void GameDesign::drawPlayButton(float x, float y) {
    menu.initPlayButton(x,y);
    _window->draw(menu._play);
}
