#ifndef GAME_MINMAX_HPP
#define GAME_MINMAX_HPP

#include <vector>
struct Move
{
    int row;
    int column;
};

class MinMax
{
  public:
    std::vector<std::vector<char>> _gameBoard;
    char _player = 'X';
    char _opponent = 'O';

    char _currPlayer = 'O';


    explicit MinMax(int size);
    explicit MinMax(int size, MinMax& otherMinMax);
    bool isEmpty(int size);
    int winner();
    void printBoard(int size);
    void swap();
    // void swap(char &currPlayer);
    void play(int size);

    int computerMove(int depth, bool isMax, int size);
    Move findBestMove(int size);


    void placeMarker(int x, int y, char player);
    void movePlayer();
    // void movePlayer(int row, int column);
};

#endif // GAME_MINMAX_HPP
