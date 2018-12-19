/*
-----------------------------------------------------------------------------------
Laboratoire : Labo08
Fichier     : rules.cpp
Auteur(s)   : Ilias Goujgali, Benoit Perret, Doran Kayoumi
Date        : 12.12.2018
But         : Contient les fonctions afin d'appliquer les règles du jeu
Remarque(s) :

Compilateur : MinGW-g++ <6.3.0>
-----------------------------------------------------------------------------------
 */

#include <string>
#include "rules.h"

bool isLegalMove(board gameBoard, std::string move) {

  char direction = move[INPUT_DIRECTION_POSITION];

  coordinate pegCoordinates = {
          charToInt(move[INPUT_ROW_POSITION]) - 1,
          charToInt(move[INPUT_COL_POSITION]) - 1
  };

  if (gameBoard[pegCoordinates[I_COORDINATE]][pegCoordinates[J_COORDINATE]] != CellState::PEG) return false;

  coordinate pegToRemove;
  coordinate newCoordinates;
  getCoordinates(pegCoordinates, pegToRemove, direction, 1);
  getCoordinates(pegCoordinates, newCoordinates, direction, MOVEMENT_SIZE);

  return gameBoard[pegToRemove[I_COORDINATE]][pegToRemove[J_COORDINATE]] == CellState::PEG and
         gameBoard[newCoordinates[I_COORDINATE]][newCoordinates[J_COORDINATE]] == CellState::HOLE;
}

void movePeg(board gameBoard, std::string move) {

  char direction = move[INPUT_DIRECTION_POSITION];
  coordinate pegCoordinates = {
          charToInt(move[INPUT_ROW_POSITION]) - 1,
          charToInt(move[INPUT_COL_POSITION]) - 1
  };

  coordinate pegToRemove;
  coordinate newCoordinates;
  getCoordinates(pegCoordinates, pegToRemove, direction, 1);
  getCoordinates(pegCoordinates, newCoordinates, direction, MOVEMENT_SIZE);

  gameBoard[pegToRemove[I_COORDINATE]][pegToRemove[J_COORDINATE]] = CellState::HOLE;
  gameBoard[pegCoordinates[I_COORDINATE]][pegCoordinates[J_COORDINATE]] = CellState::HOLE;
  gameBoard[newCoordinates[I_COORDINATE]][newCoordinates[J_COORDINATE]] = CellState::PEG;
}

void getCoordinates(coordinate currentCoordinates,
                    coordinate newCoordinates,
                    char direction,
                    unsigned movementSize) {

  newCoordinates[I_COORDINATE] = currentCoordinates[I_COORDINATE];
  newCoordinates[J_COORDINATE] = currentCoordinates[J_COORDINATE];

  switch (direction) {
    case Direction::UP:
      newCoordinates[I_COORDINATE] -= movementSize;
      break;
    case Direction::DOWN:
      newCoordinates[I_COORDINATE] += movementSize;
      break;
    case Direction::RIGHT:
      newCoordinates[J_COORDINATE] += movementSize;
      break;
    case Direction::LEFT:
      newCoordinates[J_COORDINATE] -= movementSize;
      break;
    default:;
  }
}

unsigned charToInt(const char &character) {
  return static_cast<unsigned>(character - ASCII_NUMBER_START);
}

bool isEndGame(const std::vector<std::string> &helpMoves) {
  return !helpMoves.size();
}

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
