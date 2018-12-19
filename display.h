#include "global.h"
#include <vector>

const std::string HELP_MESSAGE = "Deplacements possibles:";
const std::string ERROR_MESSAGE = "Deplacement invalide!";
const std::string QUIT_GAME_MESSAGE = "Vous avez quittez la partie";
const std::string PERFECT_MESSAGE = "Parfait, il ne reste qu'une bille au centre";
const std::string ALMOST_PERFECT_MESSAGE = "Bravo, vous avez gagne avec une seule bille restante. Au centre ce serait parfait";
const std::string NOT_BAD_MESSAGE = "Pas mal, il ne reste que ";
const std::string CAN_DO_BETTER_MESSAGE = "Vous pouvez faire mieux, il reste ";
const std::string PEG_TRANSLATION = "billes";
const std::string ASK_USER_INPUT_MESSAGE = "Que voulez-vous faire? (q pour quittez, h pour l'aide)";

const std::string OUTBOUNDS_DISPLAY_VALUE = "  ";
const std::string HOLE_DISPLAY_VALUE = "..";
const char SPACE = ' ';
const unsigned short COL_WIDTH = 3;

/**
 * @brief display the game board
 *
 * @param[board] gameBoard to display
 * @return[void]
 */
void display(board gameBoard);

/**
 * @brief display a message with the possible moves
 *
 * @param[vector] helpMoves the possible moves that can be made
 * @return[void]
 */
void displayHelpMessage(std::vector<std::string> helpMoves);

/**
 * @brief display an error message
 *
 * @return[void]
 */
void displayErrorMessage();

/**
 * @brief display the end game message
 *
 * @param[board] gameBoard in which the game was played
 * @param[unsigned] nbPegsLeft number of pegs left on the board
 * @return[void]
 */
void displayEndGame(board gameBoard, unsigned nbPegsLeft);

/**
 * @brief identify the sate of a cell and return the corresponding character
 *
 * @param[board] game board
 * @param[int] row of the cell
 * @param[int] column of the cell
 * @return[void]
 */
std::string getDisplayValue(const board gameBoard, int row, int col);

/**
 * @brief ask for user input
 *
 * @return[void]
 */
void askForUserInput();

/**
 * @brief display custom message if the user left the game
 *
 * @return[void]
 */
void displayQuitMessage();