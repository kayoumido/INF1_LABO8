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
#include "help.h"
#include <vector>
using namespace std;

int main() {
    board board;
    generate(board);
    vector<string> helpMoves =  getHelpMoves(board);
    for (string move : helpMoves)
    {
        cout << move <<" ";
    }
    cout<< endl;
    display(board);


  return 0;
}