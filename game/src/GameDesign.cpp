#include "../include/GameDesign.hpp"
#include <iostream>

void GameDesign::initVariable()
{
    this->_window = nullptr;
}

void GameDesign::initWindow()
{
    this->_videoMode.height = _height;
    this->_videoMode.width = _width;
    this->_window = new sf::RenderWindow(this->_videoMode, "Tic Tac Toe");
    this->_window->setFramerateLimit(60);
}

GameDesign::GameDesign()
{
    this->initVariable();
    this->initWindow();
    this->initLogo();
}

GameDesign::~GameDesign()
{
    delete this->_window;
}

void GameDesign::renderGame()
{
    this->_window->clear(sf::Color(98, 175, 255));
    this->_window->draw(this->_logo);
    this->drawBoard();
    this->_window->display(); //?
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
    this->_imX.loadFromFile("../resources/textures/x.png");
    this->_texX.loadFromImage(_imX);
    this->_texX.setSmooth(true);
    this->_x.setTexture(_texX);
    this->_x.setScale(sf::Vector2f(scale, scale));
    this->_x.setPosition(x, y);
}

void GameDesign::initO(float x, float y)
{
    float scale = 1.f - (static_cast<float>(_size - 3)) * 0.15f;
    this->_imO.loadFromFile("../resources/textures/o.png");
    this->_texO.loadFromImage(_imO);
    this->_texO.setSmooth(true);
    this->_o.setTexture(_texO);
    this->_o.setScale(sf::Vector2f(scale, scale));
    this->_o.setPosition(x, y);
}

void GameDesign::initBoard(float x, float y)
{
    float scale = 1.f - (static_cast<float>(_size - 3)) * 0.15f;
    this->_imBoard.loadFromFile("../resources/textures/board.png");
    this->_texBoard.loadFromImage(_imBoard);
    this->_texBoard.setSmooth(true);
    this->_board.setTexture(_texBoard);
    this->_board.setScale(sf::Vector2f(scale, scale));
    this->_board.setPosition(x, y);
}

void GameDesign::drawBoard()
{
    this->_boards.resize(_size);

    float w = (_width - 100) / (static_cast<float>(_size));
    float h = (_height - 300) / (static_cast<float>(_size));
    for(auto i = 0; i < _size; ++i)
    {
        for(auto j = 0; j < _size; j++)
        {
            this->initBoard((_firstX + i * w), (_firstY + j * h));
            this->_boards.push_back(this->_board);
        }
    }

    for(auto& i : this->_boards)
    {
        this->_window->draw(i);
    }
}
