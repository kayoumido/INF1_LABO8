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

  char board[7][7];
  string move = "22d";

  std::cout << isLegalMove(board, move) << std::endl;
  return 0;
}