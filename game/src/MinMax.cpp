#include "MinMax.hpp"
#include <iostream>

void MinMax::swap()
{
    if(_currPlayer == _human)
        _currPlayer = _computer;
    else if(_currPlayer == _computer)
        _currPlayer = _human;
}

MinMax::MinMax(int size)
{
    _human=' ';
    _computer=' ';
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
    placeMarker(row, column, _human);
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
            if(_gameBoard[i][0] == _computer)
                return 10;
            else if(_gameBoard[i][0] == _human)
                return -10;
        }

        // column
        if(_gameBoard[0][i] == _gameBoard[1][i] && _gameBoard[1][i] == _gameBoard[2][i])
        {
            if(_gameBoard[0][i] == _computer)
                return 10;
            else if(_gameBoard[0][i] == _human)
                return -10;
        }
    }
    // diagonal
    if(_gameBoard[0][0] == _gameBoard[1][1] && _gameBoard[1][1] == _gameBoard[2][2])
    {
        if(_gameBoard[1][1] == _computer)
            return 10;
        else if(_gameBoard[1][1] == _human)
            return -10;
    }
    if(_gameBoard[0][2] == _gameBoard[1][1] && _gameBoard[1][1] == _gameBoard[2][0])
    {
        if(_gameBoard[1][1] == _computer)
            return 10;
        else if(_gameBoard[1][1] == _human)
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
                    placeMarker(i, j, _computer);
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
                    placeMarker(i, j, _human);
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
    Move bestMove{-1,-1};

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(_gameBoard[i][j] == ' ')
            {
                placeMarker(i, j, _computer);
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
        if(_currPlayer == _human)
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
            placeMarker(bestMove.row, bestMove.column, _computer);
            int playerWon = winner();
            if(playerWon == 10)
            {
                printBoard(size);
                std::cout << "\n You lost! \n";
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
    _human=' ';
    _computer=' ';
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            _gameBoard[i][j] = otherMinMax._gameBoard[i][j];
        }
    }
}
void MinMax::clearBoard()
{
    for(int i = 0; i < _gameBoard.size(); ++i)
    {
        for(int j = 0; j < _gameBoard.size(); ++j)
        {
            _gameBoard[i][j] = ' ';
        }
    }
}
