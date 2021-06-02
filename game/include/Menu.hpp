#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#ifndef GAME_MENU_HPP
#define GAME_MENU_HPP

class Menu
{
  public:
    sf::Image _imMenu;
    sf::Texture _texMenu;
    sf::Sprite _menu;

    sf::Image _imChoice;
    sf::Texture _texChoice;
    sf::Sprite _choice;

    sf::Image _imPlay;
    sf::Texture _texPlay;
    sf::Sprite _play;

    /*Font object*/
    sf::Font _font;
    std::vector<sf::Text> _textSize;
    std::vector<sf::Text> _textNumber;

    /*Variables for storing text coordinates*/
    std::vector<float> _xCorSizeNumber;
    std::vector<float> _yCorSize;
    std::vector<float> _yCorNumber;

    /*!
     * Function initializes start menu
     * @param width - window width
     * @param height - window height
     */
    void initMenu(float width, float height);

    void initPlayButton(float x, float y);
    /*!
     * Function initializes selection menu
     * @param width - window width
     * @param height - window height
     */
    void initChoice(float width, float height);
};

#endif // GAME_MENU_HPP
