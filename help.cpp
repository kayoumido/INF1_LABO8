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

#include <string>
#include <iostream>
#include <vector>
#include "help.h"

std::vector<std::string> getHelpMoves(const board &gameBoard) {
  std::vector<std::string> helpMoves;
  for (unsigned row = 0; row < BOARD_ROW_SIZE; ++row) {
    for (unsigned col = 0; col < BOARD_COL_SIZE; ++col) {
      if (gameBoard[row][col] == CellState::HOLE) {
        coordinates freeCell = {row, col};
        std::vector<std::string> movePossibilities = getPossibilities(gameBoard, freeCell);
        helpMoves.insert(helpMoves.end(), movePossibilities.begin(), movePossibilities.end());
      }
    }
  }
  return helpMoves;
}

std::vector<std::string> getPossibilities(const board &gameBoard, const coordinates &freeCell) {
  std::vector<std::string> result;
  // check that the free cell isn't too close from...
  // the left side of the board

  coordinates pegToMove = {freeCell[0], freeCell[1] - 2};
  if (isOnBoard(pegToMove[1])) {
    coordinates pegToJumpOver = {freeCell[0], freeCell[1] - 1};

    if (cellHasPeg(gameBoard, pegToJumpOver) && cellHasPeg(gameBoard, pegToMove)) {
      result.push_back(formatHelpMove(Directions::RIGHT, pegToMove));
    }
  }

  // the top of the board
  pegToMove[0] = freeCell[0] - 2;
  pegToMove[1] = freeCell[1];


  if (isOnBoard(pegToMove[0])) {
    coordinates pegToJumpOver = {freeCell[0] - 1, freeCell[1]};

    if (cellHasPeg(gameBoard, pegToJumpOver) && cellHasPeg(gameBoard, pegToMove)) {

      result.push_back(formatHelpMove(Directions::DOWN, pegToMove));
    }
  }
  // the right side of the board
  pegToMove[0] = freeCell[0];
  pegToMove[1] = freeCell[1] + 2;

  if (isOnBoard(pegToMove[1])) {
    coordinates pegToJumpOver = {freeCell[0], freeCell[1] + 1};

    if (cellHasPeg(gameBoard, pegToJumpOver) && cellHasPeg(gameBoard, pegToMove)) {
      result.push_back(formatHelpMove(Directions::LEFT, pegToMove));
    }
  }

  // the bottom of the board
  pegToMove[0] = freeCell[0] + 2;
  pegToMove[1] = freeCell[1];

  if (isOnBoard(pegToMove[0])) {
    coordinates pegToJumpOver = {freeCell[0] + 1, freeCell[1]};

    if (cellHasPeg(gameBoard, pegToJumpOver) && cellHasPeg(gameBoard, pegToMove)) {
      result.push_back(formatHelpMove(Directions::UP, pegToMove));
    }
  }
  return result;
}


bool cellHasPeg(const board &gameBoard, const coordinates &pos) {
  return (gameBoard[pos[0]][pos[1]] == CellState::PEG);
}

bool isOnBoard(const unsigned &position) {
  return (position <= BOARD_COL_SIZE - 1);
}

std::string formatHelpMove(const Directions &direction, const coordinates &pos) {
  return std::to_string(pos[0] + 1) + std::to_string(pos[1] + 1) + char(direction);
}
