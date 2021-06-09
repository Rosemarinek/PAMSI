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
    isFirstMove=true;
}

Game::~Game()
{
    _doneCharX.clear();
    _doneCharO.clear();

    for(auto& i : _slot)
    {
        i.clear();
    }
    _slot.clear();
    delete minMaxGame;
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
    if(sprite.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x),
                                         static_cast<float>(event.mouseButton.y)))
        return true;
    else
        return false;
}

bool Game::elementPressed(const sf::Event& event, const sf::Text& text)
{
    if(text.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x),
                                       static_cast<float>(event.mouseButton.y)))
        return true;
    else
        return false;
}

void Game::onPlay(const sf::Event& event)
{
    if(static_cast<float>(event.mouseMove.x) > gameDesign.menu._play.getPosition().x &&
       (static_cast<float>(event.mouseMove.x) < gameDesign.menu._play.getPosition().x + 220) &&
       static_cast<float>(event.mouseMove.y) > gameDesign.menu._play.getPosition().y &&
       (static_cast<float>(event.mouseMove.y) < gameDesign.menu._play.getPosition().y + 220))
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
            onX(event);
            onO(event);
            break;
        case 4:
            onRestart(event);
            onBack(event);
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
                    initSlot();
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
            if(elementPressed(event, gameDesign.player._x))
            {
                minMaxGame->_human = 'X';
                minMaxGame->_computer = 'O';
                gameDesign.player._x.setColor(sf::Color(255, 255, 255));
            }
            else if(elementPressed(event, gameDesign.player._o))
            {
                minMaxGame->_human = 'O';
                minMaxGame->_computer = 'X';
                gameDesign.player._o.setColor(sf::Color(255, 255, 255));
            }
            _gameStatus = _gameStatus + 1;
            break;
        case 4:
            if(elementPressed(event, gameDesign.board._back))
                back();
            else if(elementPressed(event, gameDesign.board._restart))
                restart();
            else
            {
                for(int slot = 0; slot < gameDesign.board._boards.size(); ++slot)
                {
                    if(elementPressed(_event, gameDesign.board._boards[slot])&&minMaxGame->_gameBoard[slotCor(slot).row][slotCor(slot).column]==' ')
                    {
                        if(minMaxGame->_computer == 'X' && minMaxGame->_currPlayer == minMaxGame->_computer &&
                           minMaxGame->isEmpty(gameDesign._size))
                            movePlayer(slot);
                        else
                        {
                            if(minMaxGame->isEmpty(gameDesign._size)&&minMaxGame->winner(gameDesign._size,_winNumber)==0)
                                movePlayer(slot);
                            if(minMaxGame->isEmpty(gameDesign._size)&&minMaxGame->winner(gameDesign._size,_winNumber)==0)
                                moveAI();
                        }
                    }
                }
            }
            break;
        case 5:
            if(elementPressed(event, gameDesign.board._back))
                back();
            else if(elementPressed(event, gameDesign.board._restart))
                restart();
            break;
        default:
            break;
    }
}

void Game::movePlayer(int slot)
{
    int row, column;
    row = slotCor(slot).row;
    column = slotCor(slot).column;

    if(minMaxGame->_human == 'X' && minMaxGame->_gameBoard[row][column] == ' ')
    {
        gameDesign.drawX(gameDesign.board._boards[slot].getPosition().x, gameDesign.board._boards[slot].getPosition().y,
                         gameDesign._size);

        _doneCharX.push_back(gameDesign.player._x);

        minMaxGame->placeMarker(row, column, minMaxGame->_human);
        gameDesign._window->display();
    }
    else if(minMaxGame->_human == 'O' && minMaxGame->_gameBoard[row][column] == ' ')
    {
        gameDesign.drawO(gameDesign.board._boards[slot].getPosition().x, gameDesign.board._boards[slot].getPosition().y,
                         gameDesign._size);

        _doneCharO.push_back(gameDesign.player._o);

        minMaxGame->placeMarker(row, column, minMaxGame->_human);
        gameDesign._window->display();
    }
    isEnd();
    minMaxGame->swap();
}

void Game::moveAI()
{
    Move bestMove;
    if(isFirstMove && minMaxGame->_computer=='X'){
        std::srand(std::time(nullptr));
        bestMove.row=(std::rand()+333)%gameDesign._size;
        bestMove.column=(std::rand()+167)%gameDesign._size;
        isFirstMove=false;
    }
    else
        bestMove = minMaxGame->findBestMove(gameDesign._size, _winNumber);

    if(minMaxGame->_computer == 'X' && minMaxGame->_gameBoard[bestMove.row][bestMove.column] == ' ')
    {
        gameDesign.drawX(gameDesign.board._boards[_slot[bestMove.row][bestMove.column]].getPosition().x,
                         gameDesign.board._boards[_slot[bestMove.row][bestMove.column]].getPosition().y,
                         gameDesign._size);

        _doneCharX.push_back(gameDesign.player._x);

        minMaxGame->placeMarker(bestMove.row, bestMove.column, minMaxGame->_computer);
        gameDesign._window->display();
    }
    else if(minMaxGame->_computer == 'O' && minMaxGame->_gameBoard[bestMove.row][bestMove.column] == ' ')
    {
        gameDesign.drawO(gameDesign.board._boards[_slot[bestMove.row][bestMove.column]].getPosition().x,
                         gameDesign.board._boards[_slot[bestMove.row][bestMove.column]].getPosition().y,
                         gameDesign._size);

        _doneCharO.push_back(gameDesign.player._o);

        minMaxGame->placeMarker(bestMove.row, bestMove.column, minMaxGame->_computer);
        gameDesign._window->display();
    }
    isEnd();
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
            if(minMaxGame == nullptr)
            {
                minMaxGame = new MinMax(gameDesign._size);
            }
            gameDesign.drawX(gameDesign._width / 3.8f, gameDesign._height / 1.5f, 4);
            gameDesign.drawO(gameDesign._width / 1.8f, gameDesign._height / 1.5f, 4);
            break;
        case 4:
            gameDesign.drawBoard();
            gameDesign.drawBack(0, 0, 0.3f);
            gameDesign.drawRestart(520, 0, 0.3f);
            for(const auto& i : _doneCharX)
            {
                gameDesign._window->draw(i);
            }
            for(const auto& i : _doneCharO)
            {
                gameDesign._window->draw(i);
            }
            if(minMaxGame->_computer == 'X' && minMaxGame->_currPlayer == minMaxGame->_computer &&
               minMaxGame->isEmpty(gameDesign._size))
                moveAI();
            break;
        case 5:
            gameDesign.drawBack(100, 300, 0.8f);
            gameDesign.drawRestart(300, 300, 0.8f);
            break;
        default:
            break;
    }
}

void Game::onSize(const sf::Event& event)
{
    for(auto& i : gameDesign.menu._textSize)
    {
        if(static_cast<float>(event.mouseMove.x) > i.getPosition().x &&
           static_cast<float>(event.mouseMove.x) < i.getPosition().x + 80 &&
           static_cast<float>(event.mouseMove.y) > i.getPosition().y &&
           static_cast<float>(event.mouseMove.y) < i.getPosition().y + 80)
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

        if(static_cast<float>(event.mouseMove.x) > gameDesign.menu._textNumber[i].getPosition().x &&
           static_cast<float>(event.mouseMove.x) < gameDesign.menu._textNumber[i].getPosition().x + 80 &&
           static_cast<float>(event.mouseMove.y) > gameDesign.menu._textNumber[i].getPosition().y &&
           static_cast<float>(event.mouseMove.y) < gameDesign.menu._textNumber[i].getPosition().y + 80)
        {
            gameDesign.menu._textNumber[i].setFillColor(sf::Color::Red);
        }
        else
        {
            gameDesign.menu._textNumber[i].setFillColor(sf::Color::Black);
        }
    }
}

void Game::onX(const sf::Event& event)
{

    if(static_cast<float>(event.mouseMove.x) > gameDesign.player._x.getPosition().x &&
       static_cast<float>(event.mouseMove.x) < gameDesign.player._x.getPosition().x + 170 &&
       static_cast<float>(event.mouseMove.y) > gameDesign.player._x.getPosition().y &&
       static_cast<float>(event.mouseMove.y) < gameDesign.player._x.getPosition().y + 170)
    {
        gameDesign.player._x.setColor(sf::Color(0, 255, 0));
    }
    else
    {
        gameDesign.player._x.setColor(sf::Color(255, 255, 255));
    }
}

void Game::onO(const sf::Event& event)
{

    if(static_cast<float>(event.mouseMove.x) > gameDesign.player._o.getPosition().x &&
       static_cast<float>(event.mouseMove.x) < gameDesign.player._o.getPosition().x + 170 &&
       static_cast<float>(event.mouseMove.y) > gameDesign.player._o.getPosition().y &&
       static_cast<float>(event.mouseMove.y) < gameDesign.player._o.getPosition().y + 170)
    {
        gameDesign.player._o.setColor(sf::Color(0, 255, 0));
    }
    else
    {
        gameDesign.player._o.setColor(sf::Color(255, 255, 255));
    }
}

void Game::onBack(const sf::Event& event)
{
    if(static_cast<float>(event.mouseMove.x) > gameDesign.board._back.getPosition().x &&
       static_cast<float>(event.mouseMove.x) < gameDesign.board._back.getPosition().x + 100 &&
       static_cast<float>(event.mouseMove.y) > gameDesign.board._back.getPosition().y &&
       static_cast<float>(event.mouseMove.y) < gameDesign.board._back.getPosition().y + 100)
    {
        gameDesign.board._back.setColor(sf::Color(255, 0, 0));
    }
    else
    {
        gameDesign.board._back.setColor(sf::Color(255, 255, 255));
    }
}

void Game::onRestart(const sf::Event& event)
{
    if(static_cast<float>(event.mouseMove.x) > gameDesign.board._restart.getPosition().x &&
       static_cast<float>(event.mouseMove.x) < gameDesign.board._restart.getPosition().x + 100 &&
       static_cast<float>(event.mouseMove.y) > gameDesign.board._restart.getPosition().y &&
       static_cast<float>(event.mouseMove.y) < gameDesign.board._restart.getPosition().y + 100)
    {
        gameDesign.board._restart.setColor(sf::Color(0, 255, 0));
    }
    else
    {
        gameDesign.board._restart.setColor(sf::Color(255, 255, 255));
    }
}

void Game::initSlot()
{
    _slot.resize(gameDesign._size);
    for(auto& i : _slot)
    {
        i.resize(gameDesign._size);
    }

    for(int i = 0; i < _slot.size(); ++i)
    {
        for(int j = 0; j < _slot.size(); ++j)
        {
            _slot[i][j] = j + i * gameDesign._size;
        }
    }
}

void Game::restart()
{

    _gameStatus = 4;
    minMaxGame->_currPlayer = 'X';
    minMaxGame->clearBoard();
    _doneCharO.clear();
    _doneCharX.clear();
    gameDesign.board._back.setColor(sf::Color(255, 255, 255));
    gameDesign.board._restart.setColor(sf::Color(255, 255, 255));
    isFirstMove=true;
}

void Game::back()
{

    _gameStatus = 0;
    gameDesign._size = 0;
    _winNumber = 0;
    minMaxGame->_computer = ' ';
    minMaxGame->_human = ' ';
    minMaxGame = nullptr;
    _doneCharO.clear();
    _doneCharX.clear();
    isFirstMove=true;

    for(int i = 0; i < _slot.size(); ++i)
    {
        _slot.clear();
    }
    _slot.clear();

    gameDesign.clearWindow();
    gameDesign.board._back.setColor(sf::Color(255, 255, 255));
    gameDesign.board._restart.setColor(sf::Color(255, 255, 255));
}

void Game::isEnd()
{
    int playerWon = minMaxGame->winner(gameDesign._size, _winNumber);

    if(playerWon == -10)
    {
        _gameStatus = 5;
        gameDesign.clearWindow();
        gameDesign.drawText(100, 140, "PLAYER WINS!");
        gameDesign.board._back.setColor(sf::Color(255, 0, 0));
        gameDesign.board._restart.setColor(sf::Color(0, 255, 0));
    }
    else if(playerWon == 10)
    {

        _gameStatus = 5;
        gameDesign.clearWindow();
        gameDesign.drawText(40, 140, "COMPUTER WINS!");
        gameDesign.board._back.setColor(sf::Color(255, 0, 0));
        gameDesign.board._restart.setColor(sf::Color(0, 255, 0));
    }
    if(playerWon == 0 && !minMaxGame->isEmpty(gameDesign._size))
    {
        _gameStatus = 5;
        gameDesign.clearWindow();
        gameDesign.board._back.setColor(sf::Color(255, 0, 0));
        gameDesign.board._restart.setColor(sf::Color(0, 255, 0));
        gameDesign.drawText(240, 150, "TIE!");
    }
}

Move Game::slotCor(int slot)
{
    int matrixSlot = slot;
    Move move;
    matrixSlot++;
    int row, column;
    move.row = matrixSlot / gameDesign._size;
    if(matrixSlot % gameDesign._size == 0)
    {
        move.row = move.row - 1;
        move.column = gameDesign._size - 1;
    }
    else
    {
        move.column = matrixSlot % gameDesign._size - 1;
    }
    return move;
}
