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
//    char _player = 'X';
//    char _opponent = 'O';

    char _human;
    char _computer;


    char _currPlayer = 'X';

    explicit MinMax(int size);
    explicit MinMax(int size, MinMax& otherMinMax);
    bool isEmpty(int size);
    int winner(int size, int winChar);
    void printBoard(int size);
    void swap();
    void play(int size, int winChar);

    int computerMove(int depth, bool isMax, int size, int winChar);
    Move findBestMove(int size, int winChar);

    void placeMarker(int x, int y, char player);
    void movePlayer();
    void clearBoard();

};

#endif // GAME_MINMAX_HPP
