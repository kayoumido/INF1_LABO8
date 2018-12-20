/**
* @file display.h
* @brief This file contains the functions that are used to dipslay the board and some messages
*/
#include <vector>
#include "global.h"

/** 
 * Help message
*/
const std::string HELP_MESSAGE = "Deplacements possibles:";

/** 
 * Error message
*/
const std::string ERROR_MESSAGE = "Deplacement invalide!";

/** 
 * Quit game message
*/
const std::string QUIT_GAME_MESSAGE = "Vous avez quittez la partie";

/** 
 * Perfect game message
*/
const std::string PERFECT_MESSAGE = "Parfait, il ne reste qu'une bille au centre";

/** 
 * Almost perfect message
*/
const std::string ALMOST_PERFECT_MESSAGE = "Bravo, vous avez gagne avec une seule bille restante. Au centre ce serait parfait";

/** 
 * Not bad message
*/
const std::string NOT_BAD_MESSAGE = "Pas mal, il ne reste que ";

/** 
 * Can do better message
*/
const std::string CAN_DO_BETTER_MESSAGE = "Vous pouvez faire mieux, il reste ";

/** 
* Peg translation
*/
const std::string PEG_TRANSLATION = "billes";

/** 
* Ask user input message
*/
const std::string ASK_USER_INPUT_MESSAGE = "Que voulez-vous faire? (q pour quittez, h pour l'aide)";

/** 
* Outbounds display value
*/
const std::string OUTBOUNDS_DISPLAY_VALUE = "  ";

/** 
* Hole display value
*/
const std::string HOLE_DISPLAY_VALUE = "..";

/** 
* Space
*/
const char SPACE = ' ';

/** 
* Column width
*/
const unsigned short COL_WIDTH = 3;

/**
 * @brief display the game board
 *
 * @param gameBoard to display
 */
void display(board gameBoard);

/**
 * @brief display a message with the possible moves
 *
 * @param helpMoves the possible moves that can be made
 */
void displayHelpMessage(std::vector<std::string> helpMoves);

/**
 * @brief display an error message
 *
 */
void displayErrorMessage();

/**
 * @brief display the end game message
 *
 * @param gameBoard in which the game was played
 * @param nbPegsLeft number of pegs left on the board
 */
void displayEndGame(board gameBoard, unsigned nbPegsLeft);

/**
 * @brief identify the state of a cell and return the corresponding character
 *
 * @param game board
 * @param row of the cell
 * @param column of the cell
 * @return According to the state of the cell, it returns the character that will fill the cell
 */
std::string getDisplayValue(const board gameBoard, int row, int col);

/**
 * @brief ask for user input
 *
  */
void askForUserInput();

/**
 * @brief display custom message if the user left the game
 *
 */
void displayQuitMessage();