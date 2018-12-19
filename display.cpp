/*
-----------------------------------------------------------------------------------
Laboratoire : Labo08
Fichier     : Labo08.cpp
Auteur(s)   : Ilias Goujgali, Benoit Perret, Doran Kayoumi
Date        : 12.12.2018

But         :

Remarque(s) :

Compilateur : MinGW-g++ <6.3.0>
-----------------------------------------------------------------------------------
 */

#include "display.h"
#include <iostream>
#include <string>

/** Generate
 * 
 * @brief Generate the initial board disposition
 * @param board
 */
void generate(board board) {
    for (int row = 0; row < BOARD_ROW_SIZE; ++row) {
        for (int col = 0; col < BOARD_COL_SIZE; ++col) {
            // If we are currently on the position of the empty hole, we fill the array with it
            if (row == INITIAL_EMPTY_HOLE[0] and col == INITIAL_EMPTY_HOLE[1]) {
                board[row][col] = CellState::HOLE;
                continue;
            }
            // If we are on the margin of the board, the array is filled with an outbound identifier
            if ((row < MARGIN and col < MARGIN) or
                (row > BOARD_ROW_SIZE - MARGIN - 1 and col > BOARD_COL_SIZE - MARGIN - 1) or
                (row < MARGIN and col > BOARD_COL_SIZE - MARGIN - 1) or
                (row > BOARD_ROW_SIZE - MARGIN - 1 and col < MARGIN)) {
                board[row][col] = CellState::OUTBOUNDS;
                continue;
            }

            board[row][col] = CellState::PEG;
        }
    }
}

/** Display
 * 
 * @brief Display the board
 * @param board
 */
void display(board board) {
    for (int row = 0; row < BOARD_ROW_SIZE; ++row) {
        for (int col = 0; col < BOARD_COL_SIZE; ++col) {
            std::cout << getDisplayValue(board, row, col) << SPACE;
        }
        std::cout << std::endl;
    }
}

/** getDisplayValue
 * 
 * @brief Identify the cell state and return the corresponding character
 * @param board
* @param row
* @param column

 */
std::string getDisplayValue(const board board, int row, int col) {
    switch (board[row][col]) {
        case CellState::OUTBOUNDS:
            return OUTBOUNDS_DISPLAY_VALUE;
        case CellState::HOLE:
            return HOLE_DISPLAY_VALUE;
        case CellState::PEG:
            return std::to_string(row) + std::to_string(col);
        // SHOULD NEVER HAPPEN
        default:
            return "E";
    }
}