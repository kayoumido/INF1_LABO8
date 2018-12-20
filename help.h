/**
 * @file help.h
 * @brief This file contains the functions that are used to get the possible move
 *
 */
#ifndef LABO08_HELP_H
#define LABO08_HELP_H

#include "global.h"


/**
 * @brief get the possible moves the user can make
 *
 * @param gameBoard the array that represents the gameboard
 * @param freeCell coordinate of a free cell
 * @return list of the possible moves the user can make
 */
std::vector<std::string> getPossibilities(const board &gameBoard, const coordinate &freeCell);

/**
 * @brief format position with the given direction
 *
 * @param direction the direction to give to the peg
 * @param position the position of the peg to move
 * @return formatted movement
 */
std::string formatHelpMove(const Direction &direction, const coordinate &position);

/**
 * @brief check that a coordinate is still withing the board
 *
 * @param position to check
 * @return true if the position is on the board
 */
bool isOnBoard(const unsigned &position);

/**
 * @brief get all the possible moves for every free cell on the board
 *
 * @param gameBoard the gameboard with the current positions of the peg
 * @return list of all the possible moves
 */
std::vector<std::string> getHelpMoves(const board &gameBoard);

/**
 * @brief check if a cell contains a peg
 *
 * @param gameBoard the gameboard with the current positions of the peg
 * @param position the position to check if there is a peg
 * @return true if there is a peg
 */
bool cellHasPeg(const board &gameBoard, const coordinate &position);

#endif

