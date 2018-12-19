#ifndef LABO08_HELP_H
#define LABO08_HELP_H
#include "global.h"
#include <vector>


/**
 * @brief return a string with the possible moves in function of a given free cell
 *
 * @param Board
 * @param pos Direction deftype which describe position
 * @return a string which describe the possible moves
 * @return vector containing string of the help moves
 */
std::vector<std::string>  getPossibilities(board Board, coordinates pos);

/**
 * @brief format position with the given direction
 *
 * @param direction
 * @param pos
 * @return string with the possible move
 */
std::string formatHelpMove(Directions direction, coordinates pos);

/**
 * @brief Check that the position is still on the board
 *
 * @param position
 * @return bool
 */
bool isOnBoard(unsigned position);

/**
 * @brief Return help moves foreach free cells of the board
 *
 * @param gameBoard
 * @return
 */
std::vector<std::string> getHelpMoves(board gameBoard);

/**
 * @brief Return true if the given cell (row, cell indices) is a peg
 *
 * @param gameBoard
 * @param pos
 * @return
 */
bool cellHasPeg(board gameBoard, coordinates pos);

#endif

