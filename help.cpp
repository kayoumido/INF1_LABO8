#include <iostream>
#include <string>

const char CELL_HOLE = 'o';
const char CELL_BALL = '*';
const char CELL_HOLE = ' ';
const int GAME_SIZE = 7;

string getPossibilities(char gameBoard[GAME_SIZE][GAME_SIZE], int row, int col)

string helpPleaseHelpMeSniff(char gameBoard[GAME_SIZE][GAME_SIZE]) {
    string helpMoves;
    for (unsigned row = 0; row < GAME_SIZE; ++row) {
        for (unsigned col = 0; col < GAME_SIZE; ++col) {
            if (gameBoard[row][col] == CELL_HOLE) {

            }
        }
    }
}

/**
 * @brief return a string with the possible moves in function of a
 * @param gameBoard
 * @param row position
 * @param col
 * @return a string which describe the possible moves
 * @example
 */
string getPossibilities(char gameBoard[GAME_SIZE][GAME_SIZE], int row, int col) {


    string result;
    // SI la colonne n'est pas trop à droite
    if (col - 2 > 0) {
        int jumpedLeftColCell = gameBoard[row][col - 1],
    }
    // si la ligne n'est pas trop en haut
    if (row - 2 > 0) {
        int jumpedDownRowCell = gameBoard[row - 1][col];

    }
    // si la colonne n'est pas trop à droite
    if (col + 2 < GAME_SIZE - 1) {
        int jumpedRightColCell = gameBoard[row][col + 1],
    }
    // si la colonne n'est pas trop en haut
    if (row + 2 < GAME_SIZE - 1) {
        int jumpedUpRowCell = gameBoard[row + 1][col];
    }

    return result
}
