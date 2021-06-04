#include "MinMax.hpp"
#include <iostream>

void MinMax::swap()
{
    if(_currPlayer == _player)
        _currPlayer = _opponent;
    else if(_currPlayer == _opponent)
        _currPlayer = _player;
}

MinMax::MinMax(int size)
{

    _gameBoard.resize(size);
    for(int i = 0; i < size; ++i)
    {
        _gameBoard[i].resize(size);
    }

    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            _gameBoard[i][j] = ' ';
        }
    }
}

// void MinMax::movePlayer()
//{
//     int row, column;
//     std::cout << " Enter your row: ";
//     std::cin >> row;
//     std::cout << "Enter your column: ";
//     std::cin >> column;
//     std::cout << "\n";
//     placeMarker(row, column, _opponent);
// }

void MinMax::movePlayer()
{
    int row, column;
    std::cout << " Enter your row: ";
    std::cin >> row;
    std::cout << "Enter your column: ";
    std::cin >> column;
    std::cout << "\n";
    placeMarker(row, column, _opponent);
}

void MinMax::placeMarker(int x, int y, char player)
{
    _gameBoard[x][y] = player;
}

void MinMax::printBoard(int size)
{
    std::cout << "\n";
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            std::cout << _gameBoard[i][j] << " | ";
        }
        std::cout << "\n";
        std::cout << "----------\n";
    }
}

bool MinMax::isEmpty(int size)
{
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            if(_gameBoard[i][j] == ' ')
                return true;
        }
    }
    return false;
}

int MinMax::winner()
{
    for(int i = 0; i < 3; ++i)
    {
        // row
        if(_gameBoard[i][0] == _gameBoard[i][1] && _gameBoard[i][1] == _gameBoard[i][2])
        {
            if(_gameBoard[i][0] == _player)
                return 10;
            else if(_gameBoard[i][0] == _opponent)
                return -10;
        }

        // column
        if(_gameBoard[0][i] == _gameBoard[1][i] && _gameBoard[1][i] == _gameBoard[2][i])
        {
            if(_gameBoard[0][i] == _player)
                return 10;
            else if(_gameBoard[0][i] == _opponent)
                return -10;
        }
    }
    // diagonal
    if(_gameBoard[0][0] == _gameBoard[1][1] && _gameBoard[1][1] == _gameBoard[2][2])
    {
        if(_gameBoard[1][1] == _player)
            return 10;
        else if(_gameBoard[1][1] == _opponent)
            return -10;
    }
    if(_gameBoard[0][2] == _gameBoard[1][1] && _gameBoard[1][1] == _gameBoard[2][0])
    {
        if(_gameBoard[1][1] == _player)
            return 10;
        else if(_gameBoard[1][1] == _opponent)
            return -10;
    }

    return 0; // nobody won
}

int MinMax::computerMove(int depth, bool isMax, int size)
{
    int score = winner();
    if(score == 10)
        return score;

    if(score == -10)
        return score;

    if(!isEmpty(size))
        return 0;

    if(isMax)
    {
        int best = -1000;

        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {

                if(_gameBoard[i][j] == ' ')
                {
                    placeMarker(i, j, _player);
                    best = std::max(best, computerMove(depth + 1, !isMax, size));
                    placeMarker(i, j, ' ');
                }
            }
        }
        return best;
    }
    else
    {
        int best = 1000;

        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {

                if(_gameBoard[i][j] == ' ')
                {

                    placeMarker(i, j, _opponent);
                    best = std::min(best, computerMove(depth + 1, !isMax, size));
                    placeMarker(i, j, ' ');
                }
            }
        }
        return best;
    }
}

Move MinMax::findBestMove(int size)
{
    int bestVal = -1000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.column = -1;

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(_gameBoard[i][j] == ' ')
            {
                placeMarker(i, j, _player);
                int moveVal = computerMove(0, false, size);

                placeMarker(i, j, ' ');
                if(moveVal > bestVal)
                {
                    bestMove.row = i;
                    bestMove.column = j;
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}

void MinMax::play(int size)
{
    MinMax game(3);
    printBoard(size);

    for(int i = 0; i < size * size; ++i)
    {
        std::cout << "It's player " << _currPlayer << "'s turn.";
        if(_currPlayer == 'O')
        {
            movePlayer();
            int playerWon = winner();
            if(playerWon == -10)
            {
                printBoard(size);
                std::cout << "\n You won! \n";
                break;
            }
        }
        else
        {
            Move bestMove = findBestMove(size);
            placeMarker(bestMove.row, bestMove.column, _player);
            int playerWon = winner();
            if(playerWon == 10)
            {
                printBoard(size);
                std::cout << "\n You lose! \n";
                break;
            }
        }

        swap();
        printBoard(size);
    }

    int playerWon = winner();

    if(playerWon == 0)
        std::cout << "\n TIE! \n";
}

MinMax::MinMax(int size, MinMax& otherMinMax)
{
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            _gameBoard[i][j] = otherMinMax._gameBoard[i][j];
        }
    }
}
