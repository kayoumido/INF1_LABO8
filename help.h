#ifndef LABO08_HELP_H
#define LABO08_HELP_H

#include "global.h"


/**
 * @brief get the possible moves the user can make
 *
 * @param[board] gameBoard
 * @param[coordinates] freeCell
 * @return[vector] list of the possible moves the user can make
 */
std::vector<std::string> getPossibilities(const board &gameBoard, const coordinate &freeCell);

/**
 * @brief format position with the given direction
 *
 * @param[Direction] direction
 * @param[coordinate] position
 * @return[string] formatted movement
 */
std::string formatHelpMove(const Direction &direction, const coordinate &position);

/**
 * @brief check that a coordinate is still withing the board
 *
 * @param[unsigned] position to check
 * @return[bool]
 */
bool isOnBoard(const unsigned &position);

/**
 * @brief get all the possible moves for every free cell on the board
 *
 * @param[board] gameBoard
 * @return[vector] list of all the possible moves
 */
std::vector<std::string> getHelpMoves(const board &gameBoard);

/**
 * @brief check if a cell contains a peg
 *
 * @param[board] gameBoard
 * @param[coordinate] position
 * @return[bool]
 */
bool cellHasPeg(const board &gameBoard, const coordinate &position);

#endif

