#include "Player.hpp"
void Player::initX(float x, float y, int size)
{
    float scale = 1.f - (static_cast<float>(size - 3)) * 0.15f;
    _imX.loadFromFile("../resources/textures/x.png");
    _texX.loadFromImage(_imX);
    _texX.setSmooth(true);
    _x.setTexture(_texX);
    _x.setScale(sf::Vector2f(scale, scale));
    _x.setPosition(x, y);
}
void Player::initO(float x, float y, int size)
{
    float scale = 1.f - (static_cast<float>(size - 3)) * 0.15f;
    _imO.loadFromFile("../resources/textures/o.png");
    _texO.loadFromImage(_imO);
    _texO.setSmooth(true);
    _o.setTexture(_texO);
    _o.setScale(sf::Vector2f(scale, scale));
    _o.setPosition(x, y);
}
