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
