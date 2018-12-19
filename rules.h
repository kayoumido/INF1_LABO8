#ifndef LABO08_RULES_H
#define LABO08_RULES_H
#include "global.h"

const unsigned short INPUT_ROW_POSITION = 0;
const unsigned short INPUT_COL_POSITION = 1;
const unsigned short INPUT_DIRECTION_POSITION = 2;
const unsigned short ASCII_NUMBER_START = 48;
const unsigned MOVEMENT_SIZE = 2;

bool isLegalMove(board board, std::string move);
void getCoordinates(coordinates currentCoordinates, coordinates newCoordinates, char direction, unsigned movement_size);
void movePeg(board board, std::string move);
unsigned charToInt(const char &character);

#endif
