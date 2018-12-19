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

#include <iostream>
#include <string>
#include "display.h"

void generate(board board) {
    for (int row = 0; row < BOARD_ROW_SIZE; ++row) {
        for (int col = 0; col < BOARD_COL_SIZE; ++col) {

            if (row == INITIAL_EMPTY_HOLE[0] and col == INITIAL_EMPTY_HOLE[1]) {
                board[row][col] = CellState::HOLE;
                continue;
            }

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

void display(board board) {
    for (int row = 0; row < BOARD_ROW_SIZE; ++row) {
        for (int col = 0; col < BOARD_COL_SIZE; ++col) {
            std::cout << getDisplayValue(board, row, col) << SPACE;
        }
        std::cout << std::endl;
    }
}

std::string getDisplayValue(const board board, int row, int col) {
    switch (board[row][col]) {
        case CellState::OUTBOUNDS:
            return OUTBOUNDS_DISPLAY_VALUE;
        case CellState::HOLE:
            return HOLE_DISPLAY_VALUE;
        case CellState::PEG:
            return std::to_string(row + 1 ) + std::to_string(col+1);
        // SHOULD NEVER HAPPEN
        default:return "E";
    }
}