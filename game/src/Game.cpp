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
                }
                else if(_event.key.code == sf::Keyboard::M)
                {
                    //                    gameDesign.clearWindow();
                    //                    _gameStatus=0;
                    //                    gameDesign._size=0;
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

Game::Game()
{
    minMaxGame = nullptr;
    _gameStatus = 0;
    _winNumber = 0;
    clickX = 0;
    clickY = 0;
    _whoseMove = 0;
}

// Game::Game(MinMax minMaxGame) : minMaxGame(minMaxGame)
//{
//     minMaxGame=MinMax(gameDesign._size);
// }

// Game::~Game() {
//
// }

void Game::run()
{

    while(gameDesign._window->isOpen())
    {
        gameDesign._window->display();
        update();
    }
}

void Game::moveXorO()
{


    for(int i = 0; i < gameDesign._size; ++i)
    {
//        if(minMaxGame==nullptr)
//            minMaxGame = new MinMax(gameDesign._size);



        for(int j = 0; j < gameDesign._size; ++j)
        {
            if(clickX > gameDesign._xCor[i] &&
               clickX < (gameDesign._xCor[i] + (gameDesign._xCor[1] - gameDesign._xCor[0])) &&
               clickY > gameDesign._yCor[j] &&
               clickY < (gameDesign._yCor[j] + (gameDesign._yCor[1] - gameDesign._yCor[0])))
            {

                if(minMaxGame->_gameBoard[j][i] == ' ')
                {
                    if(_whoseMove % 2 == 0)
                    {
                        gameDesign.drawX(gameDesign._xCor[i], gameDesign._yCor[j]);
                        minMaxGame->placeMarker(j, i, minMaxGame->_opponent);
                        gameDesign._window->display();

                        int playerWon = minMaxGame->winner();
                        if(playerWon == -10)
                        {
                            minMaxGame->printBoard(gameDesign._size);
                            gameDesign._window->display();
                            std::cout << "\n You won! \n";
                        }
                        _whoseMove++;
                        minMaxGame->swap();
                    }
                    if(_whoseMove % 2 == 1)
                    {
                        Move bestMove = minMaxGame->findBestMove(gameDesign._size);
                        minMaxGame->placeMarker(bestMove.column, bestMove.row, minMaxGame->_player);
                        gameDesign.drawO(gameDesign._xCor[bestMove.row], gameDesign._yCor[bestMove.column]);
                        gameDesign._window->display();

                        int playerWon = minMaxGame->winner();
                        if(playerWon == 10)
                        {
                            minMaxGame->printBoard(gameDesign._size);
                            gameDesign._window->display();
                            std::cout << "\n You lose! \n";
                        }

                        _whoseMove++;
                        minMaxGame->swap();
                    }

                    gameDesign._window->display();
                    minMaxGame->printBoard(gameDesign._size);
                }
            }
        }
    }
}
//    else
//    {

//        Move bestMove = minMaxGame->findBestMove(gameDesign._size);
//        minMaxGame->placeMarker(bestMove.column, bestMove.row, minMaxGame->_player);
//        gameDesign.drawO(gameDesign._xCor[bestMove.row], gameDesign._yCor[bestMove.column]);
//        minMaxGame->printBoard(gameDesign._size);
//        _whoseMove++;
//        minMaxGame->swap();

// for(int i = 0; i < gameDesign._size; ++i)
//{
//     for(int j = 0; j < gameDesign._size; ++j)
//     {
//         if(clickX > gameDesign._xCor[i] &&
//            clickX < (gameDesign._xCor[i] + (gameDesign._xCor[1] - gameDesign._xCor[0])) &&
//            clickY > gameDesign._yCor[j] && clickY < (gameDesign._yCor[j] + (gameDesign._yCor[1] -
//            gameDesign._yCor[0])))
//         {
//
//             if(minMaxGame->_gameBoard[j][i] == ' ')
//             {
//
//                 gameDesign.drawO(gameDesign._xCor[i], gameDesign._yCor[j]);
//                 gameDesign._window->display();
//                 minMaxGame->placeMarker(j, i, minMaxGame->_player);
//                 minMaxGame->printBoard(gameDesign._size);
//                 _whoseMove++;
//                 minMaxGame->swap();
//                 // minMaxGame->_currPlayer='O';
//             }
//         }
//     }
// }
// }


void Game::onPlay(float x, float y)
{
    if(clickX > x && (clickX < x + 220) && clickY > y && (clickY < y + 220))
    {
        gameDesign.menu._play.setColor(sf::Color(140, 140, 140));
    }
    else
    {
        gameDesign.menu._play.setColor(sf::Color(255, 255, 255));
    }
}

void Game::pressPlay(float x, float y)
{
    if(clickX > x && (clickX < x + 220 && clickY > y && (clickY < y + 220)))
    {
        _gameStatus = _gameStatus + 1;
        gameDesign.clearWindow();
    }
}

void Game::checkMouseStatus()
{
    switch(_gameStatus)
    {
        case 0:
            onPlay(gameDesign._width / 3, gameDesign._height / 2.3);
            break;
        case 1:
            onSize();
            break;
        case 2:
            onNumber();
            break;
        case 3:
            onPlay(gameDesign._width / 3, gameDesign._height / 1.7);
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
            pressPlay(gameDesign._width / 3, gameDesign._height / 2.3);
            break;
        case 1:
            pressSize();
            break;
        case 2:
            pressNumber();
            break;
        case 3:
            pressPlay(gameDesign._width / 3, gameDesign._height / 1.7);
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
            minMaxGame = new MinMax(gameDesign._size);
            gameDesign.drawBoard();
            break;
    }
}

void Game::onSize()
{
    for(int i = 0; i < gameDesign.menu._textSize.size(); ++i)
    {
        if(clickX > gameDesign.menu._xCorSizeNumber[i] && clickX < gameDesign.menu._xCorSizeNumber[i] + 80 &&
           clickY > gameDesign.menu._yCorSize[i] && clickY < gameDesign.menu._yCorSize[i] + 80)
        {
            gameDesign.menu._textSize[i].setFillColor(sf::Color::Red);
        }
        else
        {
            gameDesign.menu._textSize[i].setFillColor(sf::Color::Black);
        }
    }
    gameDesign.menu._play.setColor(sf::Color(255, 255, 255));
}

void Game::onNumber()
{
    for(int i = 0; i < gameDesign._size - 2; ++i)
    {

        if(clickX > gameDesign.menu._xCorSizeNumber[i] && clickX < gameDesign.menu._xCorSizeNumber[i] + 80 &&
           clickY > gameDesign.menu._yCorNumber[i] && clickY < gameDesign.menu._yCorNumber[i] + 80)
        {
            gameDesign.menu._textNumber[i].setFillColor(sf::Color::Red);
        }
        else
        {
            gameDesign.menu._textNumber[i].setFillColor(sf::Color::Black);
        }
    }
}

void Game::pressSize()
{
    for(int i = 0; i < gameDesign.menu._textSize.size(); ++i)
    {
        if(clickX > gameDesign.menu._xCorSizeNumber[i] && clickX < gameDesign.menu._xCorSizeNumber[i] + 80 &&
           clickY > gameDesign.menu._yCorSize[i] && clickY < gameDesign.menu._yCorSize[i] + 80)
        {
            gameDesign.menu._textSize[i].setFillColor(sf::Color::Red);
            gameDesign._size = i + 3;
            _gameStatus = _gameStatus + 1;
        }
    }
}

void Game::pressNumber()
{
    for(int i = 0; i < (gameDesign._size - 2); ++i)
    {
        if(clickX > gameDesign.menu._xCorSizeNumber[i] && clickX < gameDesign.menu._xCorSizeNumber[i] + 80 &&
           clickY > gameDesign.menu._yCorNumber[i] && clickY < gameDesign.menu._yCorNumber[i] + 80)
        {
            gameDesign.menu._textNumber[i].setFillColor(sf::Color::Red);
            _winNumber = i + 3;
            _gameStatus = _gameStatus + 1;
        }
    }
}


//void Game::moveXorO()
//{
    // minMaxGame = new MinMax(gameDesign._size);
    //     if(_whoseMove % 2 == 0)
    //     {
    //         for(int i = 0; i < gameDesign._size; ++i)
    //         {
    //             for(int j = 0; j < gameDesign._size; ++j)
    //             {
    //                 if(clickX > gameDesign._xCor[i] && clickX < (gameDesign._xCor[i] + (gameDesign._xCor[1] -
    //                 gameDesign._xCor[0])) &&
    //                    clickY > gameDesign._yCor[j] && clickY < (gameDesign._yCor[j] + (gameDesign._yCor[1] -
    //                    gameDesign._yCor[0])))
    //                 {
    //
    //                     gameDesign.drawO(gameDesign._xCor[i], gameDesign._yCor[j]);
    //                     gameDesign._window->display();
    //                     _whoseMove++;
    //                 }
    //             }
    //         }
    //     }
    //     else
    //     {
    //         for(int i = 0; i < gameDesign._size; ++i)
    //         {
    //             for(int j = 0; j < gameDesign._size; ++j)
    //             {
    //                 if(clickX > gameDesign._xCor[i] && clickX < (gameDesign._xCor[i] + (gameDesign._xCor[1] -
    //                 gameDesign._xCor[0])) &&
    //                    clickY > gameDesign._yCor[j] && clickY < (gameDesign._yCor[j] + (gameDesign._yCor[1] -
    //                    gameDesign._yCor[0])))
    //                 {
    //
    //                     gameDesign.drawX(gameDesign._xCor[i], gameDesign._yCor[j]);
    //                     gameDesign._window->display();
    //                     _whoseMove++;
    //                 }
    //             }
    //         }
    //     }
//}