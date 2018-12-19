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
#include <iomanip>
#include <string>
#include "display.h"



/** Display
 * 
 * @brief Display the board
 * @param board
 */
void display(board board) {

  for (int row = 0; row < BOARD_ROW_SIZE; ++row) {
    for (int col = 0; col < BOARD_COL_SIZE; ++col) {
      std::cout << std::setw(COL_WIDTH) << std::setfill(SPACE);
      std::cout << getDisplayValue(board, row, col);
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
      return std::to_string(row + 1) + std::to_string(col + 1);
      // SHOULD NEVER HAPPEN
    default:
      return "E";
  }
}