#include "Game.hpp"
#include <iostream>

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
                if(_event.key.code == sf::Keyboard::R)
                    game.drawBoard();
                break;
            case sf::Event::MouseMoved:
                clickX = _event.mouseMove.x;
                clickY = _event.mouseMove.y;
                if(_gameStatus == 0)
                {
                    onPlay(game._width / 3, game._height / 2.3);
                    game.drawMenu();
                }
                if(_gameStatus==1)
                {
                    game.drawChoice();
                    onPlay(game._width/3, game._height/1.7);
                }
                if(_gameStatus==2){
                    game.drawBoard();
                }
                break;
            case ::sf::Event::MouseButtonReleased:
                checkGameStatus();
                break;
        }
    }
}

void Game::update()
{
    pollEvents();
}

void Game::render()
{
    game._window->display();
}

Game::Game() {}
Game::~Game() {}

void Game::run()
{
    //    if(game._window->isOpen())
    //    {
    //        render();
    //    }

    while(game._window->isOpen())
    {
        render();
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
                    std::cout << game._xCor[i] << " " << game._yCor[j] << "\n";
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
                    std::cout << game._xCor[i] << " " << game._yCor[j] << "\n";
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
    if(clickX > x &&
       (clickX < x + 220 && clickY > y && (clickY < y + 220)))
    {
        game.menu._play.setColor(sf::Color(140, 140, 140));
    }
    else
    {
        game.menu._play.setColor(sf::Color(255, 255, 255));
    }
}

void Game::pressPlay()
{
    if(clickX > game._width / 3 &&
       (clickX < game._width / 3 + 220 && clickY > game._height / 2.3 && (clickY < game._height / 2.3 + 220)))
    {
        _gameStatus = 1;
        game.clearWindow();
    }
}
void Game::checkGameStatus()
{
    switch(_gameStatus)
    {

        case 0:
            pressPlay();
            break;
        case 1:
            _gameStatus=2;
            break;
        case 2:
            _gameStatus = 3;
            break;
        case 3:
            moveXorO();
            break;
    }
}
