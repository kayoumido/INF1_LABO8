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
#include <sstream>
#include "rules.h"

bool isLegalMove(board board, std::string move) {

  char direction = move[INPUT_DIRECTION_POSITION];

  coordinates targetPeg = {
    charToInt(move[INPUT_ROW_POSITION]) - 1,
    charToInt(move[INPUT_COL_POSITION]) - 1
  };

  if (board[targetPeg[I_COORDINATE]][targetPeg[J_COORDINATE]] != CellState::PEG) return false;

  coordinates pegToRemove;
  coordinates newCoordinate;

  switch (direction) {
    case Directions::UP:
      pegToRemove[I_COORDINATE] = targetPeg[I_COORDINATE]++;
      newCoordinate[I_COORDINATE] = targetPeg[I_COORDINATE] + MOVEMENT_SIZE;
      pegToRemove[J_COORDINATE] = newCoordinate[J_COORDINATE] = targetPeg[J_COORDINATE];
      break;
    case Directions::DOWN:
      pegToRemove[I_COORDINATE] = targetPeg[I_COORDINATE]--;
      newCoordinate[I_COORDINATE] = targetPeg[I_COORDINATE] - MOVEMENT_SIZE;
      pegToRemove[J_COORDINATE] = newCoordinate[J_COORDINATE] = targetPeg[J_COORDINATE];
      break;
    case Directions::RIGHT:
      pegToRemove[J_COORDINATE] = targetPeg[J_COORDINATE]++;
      newCoordinate[J_COORDINATE] = targetPeg[J_COORDINATE] + MOVEMENT_SIZE;
      pegToRemove[I_COORDINATE] = newCoordinate[I_COORDINATE] = targetPeg[I_COORDINATE];
      break;
    case Directions::LEFT:
      pegToRemove[J_COORDINATE] = targetPeg[J_COORDINATE]--;
      newCoordinate[J_COORDINATE] = targetPeg[J_COORDINATE] - MOVEMENT_SIZE;
      pegToRemove[I_COORDINATE] = newCoordinate[I_COORDINATE] = targetPeg[I_COORDINATE];
      break;
    default:
      return false;
  }

  return board[pegToRemove[I_COORDINATE]][pegToRemove[J_COORDINATE]] == CellState::PEG and board[newCoordinate[I_COORDINATE]][newCoordinate[J_COORDINATE]];
}

void movePeg(board *board, std::string move) {

}

void getNewCoordinates(coordinates &pegCoordinates, char direction) {
  switch (direction) {
    case Directions::UP:
      pegCoordinates[I_COORDINATE] += MOVEMENT_SIZE;
      break;
    case Directions::DOWN:
      pegCoordinates[I_COORDINATE] -= MOVEMENT_SIZE;
      break;
    case Directions::RIGHT:
      pegCoordinates[J_COORDINATE] += MOVEMENT_SIZE;
      break;
    case Directions::LEFT:
      pegCoordinates[J_COORDINATE] -= MOVEMENT_SIZE;
      break;
    default:;
  }
}

unsigned charToInt(const char &character) {
  return static_cast<unsigned>(character - ASCII_NUMBER_START);
}
