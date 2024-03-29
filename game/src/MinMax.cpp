#include "MinMax.hpp"
#include <iostream>
#include <limits>

void MinMax::swap()
{
    if(_currPlayer == _human)
        _currPlayer = _computer;
    else if(_currPlayer == _computer)
        _currPlayer = _human;
}

MinMax::MinMax(int size)
{
    _human = ' ';
    _computer = ' ';
    _currPlayer = 'X';
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

MinMax::~MinMax()
{

    for(auto& i : _gameBoard)
    {
        i.clear();
    }
    _gameBoard.clear();
}

void MinMax::placeMarker(int x, int y, char player)
{
    _gameBoard[x][y] = player;
}

bool MinMax::isEmpty(int size)
{
    for(int i = 0; i < size; ++i)
        for(int j = 0; j < size; ++j)
            if(_gameBoard[i][j] == ' ')
                return true;
    return false;
}

int MinMax::winner(int size, int winChar)
{
    int counter;

    // diagonal
    for (int i = 0; i <= size - winChar; i++) {
        for (int j = 0; j <= size - winChar; j++) {
            int l = i;
            int counterAI = 0;
            int counterH = 0;
            for (int k = j ; k < winChar+j ; k++) {
                if (_gameBoard[l][k] == _computer)
                {
                    counterAI++;
                    counterH = 0;
                    if (counterAI==winChar)
                        return 10;

                }
                else if(_gameBoard[l][k] == _human)
                {
                    counterAI=0;
                    counterH++;
                    if (counterH==winChar)
                        return -10;
                }

                if (l < size - 1)
                    l++;
            }
        }
    }

    // backwards diagonal
    for (int i = 0; i <= size - winChar; i++) {
        for (int j = 0; j <= size - winChar; j++) {
            int l = i;
            int counterAI = 0;
            int counterH = 0;
            for (int k = winChar + j - 1; k >= i; k--) {
                if (_gameBoard[l][k] == _computer)
                {
                    counterAI++;
                    counterH = 0;
                    if (counterAI==winChar)
                        return 10;
                }
                else if(_gameBoard[l][k] == _human)
                {
                    counterAI=0;
                    counterH++;
                    if (counterH==winChar)
                        return -10;
                }

                if (l < size - 1)
                    l++;
            }
        }
    }

    // row
    for(int i = 0; i < size; ++i)
    {
        counter = 1;
        for(int j = 0; j < size - 1; ++j)
        {
            if(_gameBoard[i][j] == _gameBoard[i][j + 1])
                counter++;
            else
                counter = 1;

            if(_gameBoard[i][j] == _computer && counter == winChar)
                return 10;
            else if(_gameBoard[i][j] == _human && counter == winChar)
                return -10;
        }
    }

    // column
    for(int i = 0; i < size; ++i)
    {
        counter = 1;
        for(int j = 0; j < size - 1; ++j)
        {
            if(_gameBoard[j][i] == _gameBoard[j + 1][i])
            {
                counter++;
            }
            else
                counter = 1;

            if(_gameBoard[j][i] == _computer && counter == winChar)
                return 10;
            else if(_gameBoard[j][i] == _human && counter == winChar)
                return -10;
        }
    }



    return 0;
}

int MinMax::computerMove(int depth, bool isMax, int size, int winChar)
{
    int maxDepth[] = {0, 0, 0, 8, 4, 3, 3, 2, 2, 2};
    int score = winner(size, winChar);

    if(depth == maxDepth[size])
        return 0;

    if(score == 10)
        return score;

    if(score == -10)
        return score;

    if(!isEmpty(size))
        return 0;

    if(isMax)
    {
        int best = std::numeric_limits<int>::min();

        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {

                if(_gameBoard[i][j] == ' ')
                {
                    placeMarker(i, j, _computer);
                    best = std::max(best, computerMove(depth + 1, !isMax, size, winChar));
                    placeMarker(i, j, ' ');
                }
            }
        }
        return best;
    }
    else
    {
        int best = std::numeric_limits<int>::max();

        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {

                if(_gameBoard[i][j] == ' ')
                {
                    placeMarker(i, j, _human);
                    best = std::min(best, computerMove(depth + 1, !isMax, size, winChar));
                    placeMarker(i, j, ' ');
                }
            }
        }
        return best;
    }
}

Move MinMax::findBestMove(int size, int winChar)
{
    int bestVal = -1000;
    Move bestMove{-1, -1};

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(_gameBoard[i][j] == ' ')
            {
                placeMarker(i, j, _computer);
                int moveVal = computerMove(0, false, size, winChar);

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

MinMax::MinMax(int size, MinMax& otherMinMax)
{
    _human = ' ';
    _computer = ' ';
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
    for(auto& i : _gameBoard)
    {
        for(int j = 0; j < _gameBoard.size(); ++j)
        {
            i[j] = ' ';
        }
    }
}
