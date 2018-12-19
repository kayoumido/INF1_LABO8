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
#include <sstream>

#include "display.h"
#include "rules.h"
bool endOfGame = false;
const std::string ERROR_MSG = "Error message";
const char HELP = 'h';
const char WITHDRAW = 'q';

using namespace std;

int main() {
    board board;
    generate(board);
    display(board);

    string move;
    while (!endOfGame) {
        if (cin >> move) {
            if (isLegalMove(board, move) && move.length() == 3 && !isdigit(move[2])) {
                movePeg(board, move);
                display(board);

            } else {
                switch (move[0]) {
                    case HELP:
                        // Fonction help à rajouter
                        break;
                    case WITHDRAW:
                        endOfGame == true;
                        break;
                    default:
                        cout << ERROR_MSG << endl;
                        display(board);
                }
            }
        }
    }
    return 0;
}