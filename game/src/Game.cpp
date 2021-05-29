#include "../include/Game.hpp"
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
                if(_event.key.code == sf::Keyboard::Enter)
                {

                }
                break;
            case sf::Event::MouseMoved:
                clickX = _event.mouseMove.x;
                clickY = _event.mouseMove.y;
                break;
            case ::sf::Event::MouseButtonReleased:
               moveXorO();
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
    game.renderGame();
    game._window->display();
}


Game::Game(){}
Game::~Game() {}

void Game::run()
{
    if(game._window->isOpen())
    {
        render();
    }

    while(game._window->isOpen())
    {

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
