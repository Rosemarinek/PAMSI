#include "../include/Game.hpp"

void Game::pollEvents()
{
    while(game._window->pollEvent(_event))
    {
        switch(_event.type)
        {
            case sf::Event::Closed:
                this->game._window->close();
                break;
            case sf::Event::KeyPressed:
                if(this->_event.key.code == sf::Keyboard::Escape)
                    this->game._window->close();
                break;
        }
    }
}

void Game::update()
{
    this->pollEvents();
}

const bool Game::running() const
{
    return game._window->isOpen();
}

void Game::render()
{
    game.renderGame();
    game._window->display();
}
