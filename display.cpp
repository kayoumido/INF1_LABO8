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

#include "display.h"
#include <iostream>
#include <string>

using namespace std;
const int MAX_COL = 7;
const int MAX_ROW = 7;
const string EMPTY = "  ";
const char SPACE = ' ';
const string DOUBLE_DOT = "..";
const char OFF_SIDE = 'X';
const char EMPTY_CASE = 'O';
const char BUSY_CASE = '*';

void generate(board& board) {
    for (unsigned int i = 1; i <= sizeof(board[0]); i++) {
        for (unsigned int j = 1; j <= (sizeof(board[0]) / sizeof(board[0][0])); j++) {
            if ((i == 6 || i == 7 || i == 1 || i == 2) && (j == 1 || j == 2 || j == 6 || j == 7)) {
                board[i][j] = OFF_SIDE;
            } else if (i == 4 && j == 4) {
                board[i][j] = EMPTY_CASE;
            } else {
                board[i][j] = BUSY_CASE;
            }
        }
    }
}

void display(board board) {
    for (unsigned int i = 1; i <= sizeof(board[0]); i++) {
        for (unsigned int j = 1; j <= (sizeof(board[0]) / sizeof(board[0][0])); j++) {
            if (board[i][j] == OFF_SIDE) {
                cout << EMPTY << SPACE;
            } else if (board[i][j] == EMPTY_CASE) {
                cout << DOUBLE_DOT << SPACE;
            } else {
                cout << i << j << SPACE;
            }
        }
        if (i < MAX_ROW) {
            cout << endl;
        }
    }
}