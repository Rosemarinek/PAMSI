#include "../include/Game.hpp"
#include <iostream>

Game::Game()
{
    this->initVariable();
    this->initWindow();
    this->initShape();
    this->initLogo();
    this->initX();
    this->initO();
    this->initBoard(-80,-600);
}

Game::~Game()
{
    delete this->window;
}

void Game::initVariable()
{
    this->window = nullptr;
}

void Game::initWindow()
{
    this->videoMode.height = _height;
    this->videoMode.width = _width;
    this->window = new sf::RenderWindow(this->videoMode, "Tic Tac Toe");
    this->window->setFramerateLimit(60);
}

void Game::pollEvents()
{
    while(this->window->pollEvent(this->event))
    {
        switch(this->event.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if(this->event.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
        }
    }
}

void Game::update()
{
    this->pollEvents();
    this->updateMousePos();
}

void Game::render()
{
    this->window->clear(sf::Color(98,175,255));
   // this->window->draw(this->shape);
    this->window->draw(this->logo);
    this->window->draw(this->board);
   // this->drawBoard(3);
    this->window->draw(this->x);
    this->window->draw(this->o);
    this->window->display();
}

const bool Game::running() const
{
    return this->window->isOpen();
}


void Game::initShape()
{
    this->shape.setPosition(130.f, 130.f);
    this->shape.setSize(sf::Vector2f(100.f, 100.f));
    this->shape.setFillColor(sf::Color::Red);
    this->shape.setOutlineColor(sf::Color::Green);
    this->shape.setOutlineThickness(20.f);
}
void Game::updateMousePos()
{
    // update mouse position relative to screen
    //    std::cout<<"Mouse pos: x:"<<sf::Mouse::getPosition().x<<" y:"<<sf::Mouse::getPosition().y<<"\n";
    // update mouse position relative to window
//        std::cout << "Mouse pos: x:" << sf::Mouse::getPosition(*this->window).x
//                  << " y:" << sf::Mouse::getPosition(*this->window).y << "\n";
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

void Game::initLogo()
{
    float scale = _width/1700; //1700 is the width of the original logo
    this->imLogo.loadFromFile("../resources/textures/logo.png");
    this->texLogo.loadFromImage(imLogo);
    this->texLogo.setSmooth(true);
    this->logo.setTexture(texLogo);
    this->logo.setScale(sf::Vector2f(scale,scale));
    this->logo.setOrigin(sf::Vector2f(10.f,25.f));
}

void Game::initX()
{
    this->imX.loadFromFile("../resources/textures/x.png");
    this->texX.loadFromImage(imX);
    this->texX.setSmooth(true);
    this->x.setTexture(texX);
    this->x.setScale(sf::Vector2f(0.4f,0.4f));
    this->x.setOrigin(sf::Vector2f(-500.f,-600.f));
}

void Game::initO()
{
    this->imO.loadFromFile("../resources/textures/o.png");
    this->texO.loadFromImage(imO);
    this->texO.setSmooth(true);
    this->o.setTexture(texO);
    this->o.setScale(sf::Vector2f(0.4f,0.4f));
    this->o.setOrigin(sf::Vector2f(-40.f,-580.f));
}

void Game::initBoard(float x, float y)
{

    this->imBoard.loadFromFile("../resources/textures/board.png");
    this->texBoard.loadFromImage(imBoard);
    this->texBoard.setSmooth(true);
    this->board.setTexture(texBoard);
    this->board.setScale(sf::Vector2f(0.8f,0.8f));
    this->board.setOrigin(sf::Vector2f(x,y));
}

void Game::drawBoard(int size) {
    this->_boards.resize(size);

    float s = _width/float(size);

    for (int i=0; i<size; i++)
    {
       // this->_boards[i]=initBoard(s,s);
       // this->window->draw(this->_boards[i]);
    }
}
