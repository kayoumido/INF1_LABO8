/*
-----------------------------------------------------------------------------------
Laboratoire : Labo08
Fichier     : help.cpp
Auteur(s)   : Ilias Goujgali, Benoit Perret, Doran Kayoumi
Date        : 12.12.2018

But         : ce fichier contient les fonctions permettant de donner les mouvements possibles afin d'aider le joueur
              en fonction des cases vides du jeu

Remarque(s) :

Compilateur : MinGW-g++ <6.3.0>
-----------------------------------------------------------------------------------
 */



#include <iostream>
#include <string>

/**
 * @brief Return help moves foreach free cells of the gameboard
 * @param gameBoard
 * @return
 */
string getHelpMoves(board gameBoard) {
    string helpMoves;
    for (unsigned row = 0; row < BOARD_ROW_SIZE; ++row) {
        for (unsigned col = 0; col < BOARD_COL_SIZE; ++col) {
            if (gameBoard[row][col] == CellState::HOLE) {
                helpMoves += getPossibilities(gameBoard, row, col);
            }
        }
    }
    return helpMoves;
}

/**
 * @brief return a string with the possible moves in function of a given free cell
 * @param gameBoard
 * @param row index of the row
 * @param col index of the column
 * @return a string which describe the possible moves
 * @example
 */
string getPossibilities(board gameBoard, int row, int col) {
    string result;
    // check that the free cell isn't too close from...
    // the left side of the board
    if (col - 2 > 0) {
        if (cellHasPeg(gameBoard, row, col - 1) && cellHasPeg(gameBoard, row, col - 2)) {
            result += Directions::RIGHT + std::to_string(row) + std::to_string(col);
        }
    }
    // the top of the board
    if (row - 2 > 0) {
        if (cellHasPeg(gameBoard, row - 1, col) && cellHasPeg(gameBoard, row - 2, col)) {
            result += Directions::DOWN + std::to_string(row) + std::to_string(col);
        }
    }
    // the right side of the board
    if (col + 2 < BOARD_COL_SIZE - 1) {
        if (cellHasPeg(gameBoard, row, col + 1) && cellHasPeg(gameBoard, row, col + 2)) {
            result += Directions::LEFT + std::to_string(row) + std::to_string(col);
        }
    }
    // the bottom of the board
    if (row + 2 < BOARD_COL_SIZE - 1) {
        if (cellHasPeg(gameBoard, row + 1, col) && cellHasPeg(gameBoard, row + 2, col)) {
            result += Directions::UP + row + col;
        }
    }
    return result
}

/**
 * Return true if the given cell (row, cell indices) is a peg
 *
 * @param gameBoard
 * @param row
 * @param col
 * @return bool
 */
bool cellHasPeg(board gameBoard, int row, int col) {
    return (gameBoard[row][col] == CellState::PEG);
}
