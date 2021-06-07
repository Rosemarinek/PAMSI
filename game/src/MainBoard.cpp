#include "MainBoard.hpp"

void MainBoard::initLogo(float width) {
    _imLogo.loadFromFile("../resources/textures/logo.png");
    _texLogo.loadFromImage(_imLogo);
    _texLogo.setSmooth(true);
    _logo.setTexture(_texLogo);

    auto scale = static_cast<float>(width / _imLogo.getSize().x);
    _logo.setScale(sf::Vector2f(scale, scale));
    _logo.setOrigin(sf::Vector2f(10.f, 25.f));
}
void MainBoard::initBoard(float x, float y, int size)
{
    float scale = 1.f - (static_cast<float>(size - 3)) * 0.15f;
    _imBoard.loadFromFile("../resources/textures/board.png");
    _texBoard.loadFromImage(_imBoard);
    _texBoard.setSmooth(true);
    _board.setTexture(_texBoard);
    _board.setScale(sf::Vector2f(scale, scale));
    _board.setPosition(x, y);
}

void MainBoard::initBack(float x, float y, float scale)
{
    _imBack.loadFromFile("../resources/textures/backtomenu.png");
    _texBack.loadFromImage(_imBack);
    _texBack.setSmooth(true);
    _back.setTexture(_texBack);
    _back.setScale(sf::Vector2f(scale, scale));
    _back.setPosition(x, y);
}

void MainBoard::initRestart(float x, float y, float scale)
{
    _imRestart.loadFromFile("../resources/textures/restart.png");
    _texRestart.loadFromImage(_imRestart);
    _texRestart.setSmooth(true);
    _restart.setTexture(_texRestart);
    _restart.setScale(sf::Vector2f(scale, scale));
    _restart.setPosition(x, y);
}
void MainBoard::initText(float x, float y, std::string text)
{
    _font.loadFromFile("../resources/fonts/Winkle.ttf");
    _text.setFont(_font);
    _text.setFillColor(sf::Color(0,0,0));
    _text.setString(text);
    _text.setPosition(sf::Vector2f(x,y));
    _text.setCharacterSize(80);
}
