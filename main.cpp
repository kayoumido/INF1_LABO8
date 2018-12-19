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
#include "display.h"
#include "rules.h"
#include "help.h"
#include "userInput.h"

#include <vector>

using namespace std;

int main() {
  const string QUIT_COMMAND = "q";
  const string HELP_COMMAND = "h";
  board board;
  generate(board);

  string move;
  bool endGame = false;
  unsigned nbPegs = BOARD_ROW_SIZE * BOARD_COL_SIZE - 4 * (MARGIN * MARGIN) - 1;
  do {
    display(board);
    cout << "Déplacement : ";
    cin >> move;

    if (isCommand(move, QUIT_COMMAND)) {
      endGame = true;
      continue;
    }

    if (isCommand(move, HELP_COMMAND)) {
      displayHelpMessage(getHelpMoves(board));
    }

    if (!isValidInput(move)) {
      displayErrorMessage();
      continue;
    }

    if (isLegalMove(board, move)) {
      movePeg(board, move);
      nbPegs--;
    } else {
      displayErrorMessage();
      continue;
    }

    if (isEndGame(getHelpMoves(board))) {
      endGame = true;
      display(board);
      continue;
    }

    cout << endl;
  } while (!endGame);

  displayEndGame(board, nbPegs);

  return 0;
}