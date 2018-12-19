#ifndef LABO08_HELP_H
#define LABO08_HELP_H
#include "global.h"
#include <string>

std::string getPossibilities(board Board, int row, int col);

bool cellHasPeg(board gameBoard, int row, int col);

std::string getHelpMoves(board gameBoard);

#endif

