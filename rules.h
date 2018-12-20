/**
 * @file rules.h
 * @brief this file contains the function that implement the game logic
*/

#ifndef LABO08_RULES_H
#define LABO08_RULES_H

#include "global.h"
#include <vector>
#include <string>

const unsigned short ASCII_NUMBER_START = 48;
const unsigned MOVEMENT_SIZE = 2;

/**
 * @brief check if the move entered by the user is valid
 *
 * @param[board] game board
 * @param[string] move entered by the user
 * @return[boolean] true if it's valid otherwise false
 */
bool isLegalMove(board gameBoard, std::string move);

/**
 * @biref get the coordinates based of existing coordinates
 *
 * @param[coordinate] currentCoordinates existing coordinates
 * @param[coordinate] newCoordinates container for the new containers
 * @param[char] direction in which to move
 * @param[unsigned] movementSize size of the movement
 * @return[void]
 */
void getCoordinates(coordinate currentCoordinates, coordinate newCoordinates, char direction, unsigned movementSize);

/**
 * @brief move a peg within a game board
 *
 * @param[board] game board
 * @param[string] move to perform (coordinates in the board an direction in which to move)
 * @return[void]
 */
void movePeg(board gameBoard, std::string move);

/**
 * @brief convert a char into an int
 *
 * @param[char] character to converter
 * @return[unsigned] the converted value
 */
unsigned charToInt(const char &character);

/**
 * @brief check if the game is finished. i.e there aren't any moves left
 *
 * @param helpMoves vector of possible moves
 * @return bool
 */
bool isEndGame(const std::vector<std::string> &helpMoves);

/**
 * @brief generate(fill) a board game
 *
 * @param board game board
 * @return[void]
 */
void generate(board);

#endif
