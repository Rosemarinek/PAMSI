#ifndef GAME_MINMAX_HPP
#define GAME_MINMAX_HPP

#include <vector>

/*!
 * Structures storing movement coordinates
 */
struct Move
{
    int row;
    int column;
};

/*!
 * Class responsible for min man algorithm
 */
class MinMax
{
  public:
    std::vector<std::vector<char>> _gameBoard;

    /*Player character*/
    char _human;
    /*Computer character*/
    char _computer;
    /*Variables storing the sign of the current player*/
    char _currPlayer;

    /*Constructor and destructor*/
    explicit MinMax(int size);
    explicit MinMax(int size, MinMax& otherMinMax);
    ~MinMax();

    /*!
     * Function checks if there are free slots left
     * @param size - game size
     * @return - true if there are free slots left or false if there aren't
     */
    bool isEmpty(int size);
    /*!
     * Function checks if someone has won
     * @param size - game size
     * @param winChar - number of winning characters
     * @return
     */
    int winner(int size, int winChar);
    /*!
     * Function changes the character of the current player
     */
    void swap();
    /*!
     * Function based od min max algorithm.
     * @param depth - how deep is the algorithm supposed to go
     * @param isMax - argument to determine if the current move is by computer
     * @param size - game size
     * @param winChar - number of winning characters
     * @return - the best value for move
     */
    int computerMove(int depth, bool isMax, int size, int winChar);
    /*!
     * Function evaluates all the available moved using computerMove() with min max algorithm
     * @param size - game size
     * @param winChar - number of winning characters
     * @return the best move the maximizer can make
     */
    Move findBestMove(int size, int winChar);
    /*!
     * Function places a mark in the appropriate position in the matrix
     * @param x - x coordinate
     * @param y - y coordinate
     * @param player - character of the current player
     */
    void placeMarker(int x, int y, char player);
    /*!
     * Function removes all characters from the matrix
     */
    void clearBoard();

    void printBoard(int size);
};

#endif // GAME_MINMAX_HPP
