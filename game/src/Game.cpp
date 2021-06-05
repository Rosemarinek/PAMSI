#include "Game.hpp"
#include <iostream>

void Game::pollEvents()
{

    while(gameDesign._window->pollEvent(_event))
    {
        switch(_event.type)
        {
            case sf::Event::Closed:
                gameDesign._window->close();
                break;
            case sf::Event::KeyPressed:
                if(_event.key.code == sf::Keyboard::Escape)
                    gameDesign._window->close();
                else if(_event.key.code == sf::Keyboard::R && _gameStatus == 5)
                {
                    gameDesign.drawBoard();
                    _whoseMove = 0;
                    minMaxGame = new MinMax(gameDesign._size);
                }
                else if(_event.key.code == sf::Keyboard::M)
                {
                    minMaxGame = new MinMax(gameDesign._size);
                    _whoseMove = 0;
                    gameDesign._size = 0;
                    _winNumber = 0;
                    gameDesign.clearWindow();
                    _gameStatus = 0;

                    // TODO: Back to menu
                }
                break;
            case sf::Event::MouseMoved:
                checkMouseStatus(_event);
                break;
            case ::sf::Event::MouseButtonReleased:
                checkClickStatus(_event);
                break;
        }
    }
}

void Game::update()
{
    pollEvents();
    checkGameStatus();
}

Game::Game()
{
    minMaxGame = nullptr;
    _gameStatus = 0;
    _winNumber = 0;
    _whoseMove = 0;
}

void Game::run()
{

    while(gameDesign._window->isOpen())
    {
        gameDesign._window->display();
        update();
    }
}

bool Game::elementPressed(const sf::Event& event, const sf::Sprite& sprite)
{
    if(sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
        return true;
    else
        return false;
}

bool Game::elementPressed(const sf::Event& event, const sf::Text& text)
{
    if(text.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
        return true;
    else
        return false;
}

void Game::onPlay(const sf::Event& event)
{

    if(event.mouseMove.x > gameDesign.menu._play.getPosition().x &&
       (event.mouseMove.x < gameDesign.menu._play.getPosition().x + 220) &&
       event.mouseMove.y > gameDesign.menu._play.getPosition().y &&
       (event.mouseMove.y < gameDesign.menu._play.getPosition().y + 220))
    {
        gameDesign.menu._play.setColor(sf::Color(140, 140, 140));
    }
    else
    {
        gameDesign.menu._play.setColor(sf::Color(255, 255, 255));
    }
}

void Game::checkMouseStatus(const sf::Event& event)
{
    switch(_gameStatus)
    {
        case 0:
            onPlay(event);
            break;
        case 1:
            onSize(event);
            break;
        case 2:
            onNumber(event);
            break;
        case 3:
            onPlay(event);
            break;
        case 4:
            _gameStatus = 5;
            break;
        default:
            break;
    }
}

void Game::checkClickStatus(const sf::Event& event)
{
    switch(_gameStatus)
    {
        case 0:
            if(elementPressed(event, gameDesign.menu._play))
                _gameStatus = _gameStatus + 1;
            break;
        case 1:
            for(int i = 0; i < gameDesign.menu._textSize.size(); ++i)
            {
                if(elementPressed(event, gameDesign.menu._textSize[i]))
                {
                    gameDesign.menu._textSize[i].setFillColor(sf::Color::Red);
                    gameDesign._size = i + 3;
                    _gameStatus = _gameStatus + 1;
                }
            }
            break;
        case 2:
            for(int i = 0; i < gameDesign.menu._textNumber.size(); ++i)
            {
                if(elementPressed(event, gameDesign.menu._textNumber[i]))
                {
                    gameDesign.menu._textNumber[i].setFillColor(sf::Color::Red);
                    _winNumber = i + 3;
                    _gameStatus = _gameStatus + 1;
                }
            }
            break;
        case 3:
            if(elementPressed(event, gameDesign.menu._play))
                _gameStatus = _gameStatus + 1;
            break;
        case 5:
            moveXorO();
            break;
        default:
            break;
    }
}

void Game::movePlayer(int row, int column, int slot)
{

    gameDesign.drawO(gameDesign.board._boards[slot].getPosition().x, gameDesign.board._boards[slot].getPosition().y);
    minMaxGame->placeMarker(row, column, minMaxGame->_opponent);
    minMaxGame->printBoard(gameDesign._size);
    gameDesign._window->display();
    _whoseMove++;
    minMaxGame->swap();
    gameDesign._window->display();
}

void Game::moveXorO()
{

    for(int slot = 0; slot < gameDesign.board._boards.size(); ++slot)
    {
        if(elementPressed(_event, gameDesign.board._boards[slot]))
        {
            if(minMaxGame->_currPlayer=='X')
            {
                gameDesign.drawX(gameDesign.board._boards[slot].getPosition().x,
                                 gameDesign.board._boards[slot].getPosition().y);
                gameDesign._window->display();
            }
            else
            {
                gameDesign.drawO(gameDesign.board._boards[slot].getPosition().x,
                                 gameDesign.board._boards[slot].getPosition().y);
                gameDesign._window->display();

            }
        }
    }
    minMaxGame->swap();
}


void Game::checkGameStatus()
{
    switch(_gameStatus)
    {
        case 0:
            gameDesign.drawMenu();
            break;
        case 1:
            gameDesign.drawChoice();
            break;
        case 2:
            gameDesign.drawChoice();
            break;
        case 3:
            gameDesign.drawChoice();
            gameDesign.drawPlayButton(gameDesign._width / 3, gameDesign._height / 1.7);
            break;
        case 4:
            if(minMaxGame == nullptr)
            {
                minMaxGame = new MinMax(gameDesign._size);
            }
            gameDesign.drawBoard();
            break;
    }
}

void Game::onSize(const sf::Event& event)
{
    for(auto& i : gameDesign.menu._textSize)
    {
        if(event.mouseMove.x > i.getPosition().x && event.mouseMove.x < i.getPosition().x + 80 &&
           event.mouseMove.y > i.getPosition().y && event.mouseMove.y < i.getPosition().y + 80)
        {
            i.setFillColor(sf::Color::Red);
        }
        else
        {
            i.setFillColor(sf::Color::Black);
        }
    }
    gameDesign.menu._play.setColor(sf::Color(255, 255, 255));
}

void Game::onNumber(const sf::Event& event)
{
    for(int i = 0; i < gameDesign._size - 2; ++i)
    {

        if(event.mouseMove.x > gameDesign.menu._textNumber[i].getPosition().x &&
           event.mouseMove.x < gameDesign.menu._textNumber[i].getPosition().x + 80 &&
           event.mouseMove.y > gameDesign.menu._textNumber[i].getPosition().y &&
           event.mouseMove.x < gameDesign.menu._textNumber[i].getPosition().y + 80)
        {
            gameDesign.menu._textNumber[i].setFillColor(sf::Color::Red);
        }
        else
        {
            gameDesign.menu._textNumber[i].setFillColor(sf::Color::Black);
        }
    }
}
