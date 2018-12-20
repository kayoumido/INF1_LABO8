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
 * @param game board
 * @param move entered by the user
 * @return true if it's valid otherwise false
 */
bool isLegalMove(board gameBoard, std::string move);

/**
 * @brief get the coordinates based of existing coordinates
 *
 * @param currentCoordinates existing coordinates
 * @param newCoordinates container for the new containers
 * @param direction in which to move
 * @param movementSize size of the movement
 * @return
 */
void getCoordinates(coordinate currentCoordinates, coordinate newCoordinates, char direction, unsigned movementSize);

/**
 * @brief move a peg within a game board
 *
 * @param game board
 * @param move to perform (coordinates in the board an direction in which to move)
 */
void movePeg(board gameBoard, std::string move);

/**
 * @brief convert a char into an int
 *
 * @param character to converter
 * @return the converted value
 */
unsigned charToInt(const char &character);

/**
 * @brief check if the game is finished. i.e there aren't any moves left
 *
 * @param helpMoves vector of possible moves
 * @return true if there is no move to do
 */
bool isEndGame(const std::vector<std::string> &helpMoves);

/**
 * @brief generate(fill) a board game
 *
 * @param board game board
 */
void generate(board);

#endif
