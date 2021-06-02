#include "Game.hpp"

void Game::pollEvents()
{

    while(game._window->pollEvent(_event))
    {
        switch(_event.type)
        {
            case sf::Event::Closed:
                game._window->close();
                break;
            case sf::Event::KeyPressed:
                if(_event.key.code == sf::Keyboard::Escape)
                    game._window->close();
                else if(_event.key.code == sf::Keyboard::R && _gameStatus == 5)
                    game.drawBoard();
                else if(_event.key.code == sf::Keyboard::M)
                {
                    //                    game.clearWindow();
                    //                    _gameStatus=0;
                    //                    game._size=0;
                    //                    _winNumber=0;
                    // TODO: Back to menu
                }
                break;
            case sf::Event::MouseMoved:
                clickX = _event.mouseMove.x;
                clickY = _event.mouseMove.y;
                checkMouseStatus();
                break;
            case ::sf::Event::MouseButtonReleased:
                checkClickStatus();
                break;
        }
    }
}

void Game::update()
{
    pollEvents();
    checkGameStatus();
}

Game::Game() {}
Game::~Game() {}

void Game::run()
{

    while(game._window->isOpen())
    {
        game._window->display();

        // render();
        update();
    }
}

void Game::moveXorO()
{
    if(_whoseMove % 2 == 0)
    {
        for(int i = 0; i < game._size; ++i)
        {
            for(int j = 0; j < game._size; ++j)
            {
                if(clickX > game._xCor[i] && clickX < (game._xCor[i] + (game._xCor[1] - game._xCor[0])) &&
                   clickY > game._yCor[j] && clickY < (game._yCor[j] + (game._yCor[1] - game._yCor[0])))
                {

                    game.drawX(game._xCor[i], game._yCor[j]);
                    game._window->display();
                }
            }
        }
        _whoseMove++;
    }
    else if(_whoseMove % 2 == 1)
    {
        for(int i = 0; i < game._size; ++i)
        {
            for(int j = 0; j < game._size; ++j)
            {
                if(clickX > game._xCor[i] && clickX < (game._xCor[i] + (game._xCor[1] - game._xCor[0])) &&
                   clickY > game._yCor[j] && clickY < (game._yCor[j] + (game._yCor[1] - game._yCor[0])))
                {

                    game.drawO(game._xCor[i], game._yCor[j]);
                    game._window->display();
                }
            }
        }
        _whoseMove++;
    }
}

void Game::onPlay(float x, float y)
{
    if(clickX > x && (clickX < x + 220) && clickY > y && (clickY < y + 220))
    {
        game.menu._play.setColor(sf::Color(140, 140, 140));
    }
    else
    {
        game.menu._play.setColor(sf::Color(255, 255, 255));
    }
}

void Game::pressPlay(float x, float y)
{
    if(clickX > x && (clickX < x + 220 && clickY > y && (clickY < y + 220)))
    {
        _gameStatus = _gameStatus + 1;
        game.clearWindow();
    }
}

void Game::checkMouseStatus()
{
    switch(_gameStatus)
    {
        case 0:
            onPlay(game._width / 3, game._height / 2.3);
            break;
        case 1:
            onSize();
            break;
        case 2:
            onNumber();
            break;
        case 3:
            onPlay(game._width / 3, game._height / 1.7);
            break;
        case 4:
            _gameStatus = 5;
            break;
    }
}

void Game::checkClickStatus()
{
    switch(_gameStatus)
    {
        case 0:
            pressPlay(game._width / 3, game._height / 2.3);
            break;
        case 1:
            pressSize();
            break;
        case 2:
            pressNumber();
            break;
        case 3:
            pressPlay(game._width / 3, game._height / 1.7);
            break;
        case 5:
            moveXorO();
            break;
    }
}

void Game::checkGameStatus()
{
    switch(_gameStatus)
    {
        case 0:
            game.drawMenu();
            break;
        case 1:
            game.drawChoice();
            break;
        case 2:
            game.drawChoice();
            break;
        case 3:
            game.drawChoice();
            game.drawPlayButton(game._width / 3, game._height / 1.7);
            break;
        case 4:
            game.drawBoard();
            break;
    }
}

void Game::onSize()
{
    for(int i = 0; i < game.menu._textSize.size(); ++i)
    {
        if(clickX > game.menu._xCorSizeNumber[i] && clickX < game.menu._xCorSizeNumber[i] + 80 &&
           clickY > game.menu._yCorSize[i] && clickY < game.menu._yCorSize[i] + 80)
        {
            game.menu._textSize[i].setFillColor(sf::Color::Red);
        }
        else
        {
            game.menu._textSize[i].setFillColor(sf::Color::Black);
        }
    }
    game.menu._play.setColor(sf::Color(255, 255, 255));
}

void Game::onNumber()
{
    for(int i = 0; i < game._size - 2; ++i)
    {

        if(clickX > game.menu._xCorSizeNumber[i] && clickX < game.menu._xCorSizeNumber[i] + 80 &&
           clickY > game.menu._yCorNumber[i] && clickY < game.menu._yCorNumber[i] + 80)
        {
            game.menu._textNumber[i].setFillColor(sf::Color::Red);
        }
        else
        {
            game.menu._textNumber[i].setFillColor(sf::Color::Black);
        }
    }
}

void Game::pressSize()
{
    for(int i = 0; i < game.menu._textSize.size(); ++i)
    {
        if(clickX > game.menu._xCorSizeNumber[i] && clickX < game.menu._xCorSizeNumber[i] + 80 &&
           clickY > game.menu._yCorSize[i] && clickY < game.menu._yCorSize[i] + 80)
        {
            game.menu._textSize[i].setFillColor(sf::Color::Red);
            game._size = i + 3;
            _gameStatus = _gameStatus + 1;
        }
    }
}

void Game::pressNumber()
{
    for(int i = 0; i < (game._size - 2); ++i)
    {
        if(clickX > game.menu._xCorSizeNumber[i] && clickX < game.menu._xCorSizeNumber[i] + 80 &&
           clickY > game.menu._yCorNumber[i] && clickY < game.menu._yCorNumber[i] + 80)
        {
            game.menu._textNumber[i].setFillColor(sf::Color::Red);
            _winNumber = i + 3;
            _gameStatus = _gameStatus + 1;
        }
    }
}
