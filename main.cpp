/*
-----------------------------------------------------------------------------------
Laboratoire : Labo08
Fichier     : main.cpp
Auteur(s)   : Ilias Goujgali, Benoit Perret, Doran Kayoumi
Date        : 12.12.2018

But         :

Remarque(s) :

Compilateur : MinGW-g++ <6.3.0>
-----------------------------------------------------------------------------------
 */

#include <iostream>
#include "rules.h"

using namespace std;

int main() {

  board board;
  string move = "42d";

  for (int i = 0; i < BOARD_ROW_SIZE; ++i) {
    for (int j = 0; j < BOARD_COL_SIZE; ++j) {
      if ((i == 0 and j == 1) or (i == 1 and j == 0) or (i == 0 and j == 0) or (i == 1 and j == 1) or
          (i == 5 and j == 5) or (i == 5 and j == 6) or (i == 6 and j == 5) or (i == 6 and j == 6) or
          (i == 0 and j == 5) or (i == 0 and j == 6) or (i == 1 and j == 5) or (i == 1 and j == 6) or
          (i == 5 and j == 1) or (i == 5 and j == 0) or (i == 6 and j == 1) or (i == 6 and j == 0)) {
        board[i][j] = CellState::OUTBOUNDS;
        continue;
      }

      if (i == 3 and j == 3) {
        board[i][j] = CellState::HOLE;
        continue;
      }

      board[i][j] = CellState::PEG;
    }
  }

  if (isLegalMove(board, move)) {
    movePeg(board, move);
  }
  return 0;
}