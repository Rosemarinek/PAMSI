#include "../include/Menu.hpp"

void Menu::initMenu(float width, float height) {
    _imMenu.loadFromFile("../resources/textures/menu.png");
    _texMenu.loadFromImage(_imMenu);
    _texMenu.setSmooth(true);
    _menu.setTexture(_texMenu);
    _menu.setScale(sf::Vector2f(1.f, 1.f));
    _menu.setPosition(0, 0);

}

void Menu::initChoice(float width, float height) {
    _imChoice.loadFromFile("../resources/textures/choice.png");
    _texChoice.loadFromImage(_imChoice);
    _texChoice.setSmooth(true);
    _choice.setTexture(_texChoice);
    _choice.setScale(sf::Vector2f(1.f, 1.f));
    _choice.setPosition(0, 0);

    _textSize.resize(6);
    _textNumber.resize(6);
    _font.loadFromFile("../resources/fonts/Winkle.ttf");

    for(int i = 0; i < _textSize.size(); i++)
    {
        _textSize[i].setFont(_font);
        _textSize[i].setFillColor(sf::Color::Black);
        _textSize[i].setString(std::to_string(i+3));
        _textSize[i].setPosition(sf::Vector2f((width /7.8+i*80), height / 5.1));
        _textSize[i].setCharacterSize(90);

        _textNumber[i].setFont(_font);
        _textNumber[i].setFillColor(sf::Color::Black);
        _textNumber[i].setString(std::to_string(i+3));
        _textNumber[i].setPosition(sf::Vector2f((width /7.8+i*80), height / 2.25));
        _textNumber[i].setCharacterSize(90);

    }

}
void Menu::initPlayButton(float x, float y) {
    _imPlay.loadFromFile("../resources/textures/play.png");
    _texPlay.loadFromImage(_imPlay);
    _texPlay.setSmooth(true);
    _play.setTexture(_texPlay);
    _play.setScale(sf::Vector2f(0.6f, 0.6f));
    _play.setPosition(x, y);
}
