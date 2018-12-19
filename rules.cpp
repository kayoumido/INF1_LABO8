/*
-----------------------------------------------------------------------------------
Laboratoire : Labo08
Fichier     : rules.cpp
Auteur(s)   : Ilias Goujgali, Benoit Perret, Doran Kayoumi
Date        : 12.12.2018
But         :
Remarque(s) :

Compilateur : MinGW-g++ <6.3.0>
-----------------------------------------------------------------------------------
 */

#include <string>
#include "rules.h"

bool isLegalMove(board board, std::string move) {

  char direction = move[INPUT_DIRECTION_POSITION];

  coordinates pegCoordinates = {
    charToInt(move[INPUT_ROW_POSITION]) - 1,
    charToInt(move[INPUT_COL_POSITION]) - 1
  };

  if (board[pegCoordinates[I_COORDINATE]][pegCoordinates[J_COORDINATE]] != CellState::PEG) return false;

  coordinates pegToRemove;
  coordinates newCoordinates;
  getCoordinates(pegCoordinates, pegToRemove, direction, 1);
  getCoordinates(pegCoordinates, newCoordinates, direction, MOVEMENT_SIZE);

  return board[pegToRemove[I_COORDINATE]][pegToRemove[J_COORDINATE]] == CellState::PEG and
        board[newCoordinates[I_COORDINATE]][newCoordinates[J_COORDINATE]] == CellState::HOLE;
}

void movePeg(board board, std::string move) {

  char direction = move[INPUT_DIRECTION_POSITION];
  coordinates pegCoordinates = {
    charToInt(move[INPUT_ROW_POSITION]) - 1,
    charToInt(move[INPUT_COL_POSITION]) - 1
  };

  coordinates pegToRemove;
  coordinates newCoordinates;
  getCoordinates(pegCoordinates, pegToRemove, direction, 1);
  getCoordinates(pegCoordinates, newCoordinates, direction, MOVEMENT_SIZE);

  board[pegToRemove[I_COORDINATE]][pegToRemove[J_COORDINATE]] = CellState::HOLE;
  board[pegCoordinates[I_COORDINATE]][pegCoordinates[J_COORDINATE]] = CellState::HOLE;
  board[newCoordinates[I_COORDINATE]][newCoordinates[J_COORDINATE]] = CellState::PEG;
}

void getCoordinates(coordinates currentCoordinates,
                    coordinates newCoordinates,
                    char direction,
                    unsigned movementSize) {

  newCoordinates[I_COORDINATE] = currentCoordinates[I_COORDINATE];
  newCoordinates[J_COORDINATE] = currentCoordinates[J_COORDINATE];

  switch (direction) {
    case Directions::UP:
      newCoordinates[I_COORDINATE] += movementSize;
      break;
    case Directions::DOWN:
      newCoordinates[I_COORDINATE] -= movementSize;
      break;
    case Directions::RIGHT:
      newCoordinates[J_COORDINATE] += movementSize;
      break;
    case Directions::LEFT:
      newCoordinates[J_COORDINATE] -= movementSize;
      break;
    default:;
  }
}

unsigned charToInt(const char &character) {
  return static_cast<unsigned>(character - ASCII_NUMBER_START);
}
