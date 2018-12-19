/*
-----------------------------------------------------------------------------------
Laboratoire : Labo08
Fichier     : display.cpp
Auteur(s)   : Ilias Goujgali, Benoit Perret, Doran Kayoumi
Date        : 12.12.2018

But         : Contient toute les fonctions liés à l'affichage

Remarque(s) :

Compilateur : MinGW-g++ <6.3.0>
-----------------------------------------------------------------------------------
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include "display.h"


void display(board gameBoard) {
  std::cout << std::endl;
  for (int row = 0; row < BOARD_ROW_SIZE; ++row) {
    for (int col = 0; col < BOARD_COL_SIZE; ++col) {
      std::cout << std::setw(COL_WIDTH) << std::setfill(SPACE);
      std::cout << getDisplayValue(gameBoard, row, col);
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}


std::string getDisplayValue(const board gameBoard, int row, int col) {
  switch (gameBoard[row][col]) {
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

void displayHelpMessage(std::vector<std::string> helpMoves) {
  std::cout << HELP_MESSAGE << " ";

  for (std::string move : helpMoves) {
    std::cout << move << " ";
  }
  std::cout << std::endl;
}

void displayErrorMessage() {
  std::cout << ERROR_MESSAGE << std::endl;
}

void displayEndGame(board gameBoard, unsigned nbPegsLeft) {

  if (nbPegsLeft == 1) {
    // if the last is on the center of the gameBoard
    if (gameBoard[INITIAL_EMPTY_HOLE[I_COORDINATE]][INITIAL_EMPTY_HOLE[J_COORDINATE]] == CellState::PEG) {
      std::cout << PERFECT_MESSAGE;
    } else {
      std::cout << ALMOST_PERFECT_MESSAGE;
    }
  } else if (nbPegsLeft >= 2 && nbPegsLeft <= 5) {
    std::cout << NOT_BAD_MESSAGE << nbPegsLeft << " " << PEG_TRANSLATION;
  } else {
    std::cout << CAN_DO_BETTER_MESSAGE << nbPegsLeft << " " << PEG_TRANSLATION;
  }
  std::cout << std::endl;
}

void displayQuitMessage() {
  std::cout << QUIT_GAME_MESSAGE << std::endl;
}

void askForUserInput() {
  std::cout << ASK_USER_INPUT_MESSAGE << std::endl;
}