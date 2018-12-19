#ifndef LABO08_GLOBAL_H
#define LABO08_GLOBAL_H

const unsigned short BOARD_COL_SIZE = 7;
const unsigned short BOARD_ROW_SIZE = 7;
const unsigned short MARGIN = 2;
const unsigned short INITIAL_EMPTY_HOLE[] = {3, 3};
const unsigned short COORDINATES_SIZE = 2;
const unsigned short I_COORDINATE = 0;
const unsigned short J_COORDINATE = 1;
const unsigned short INPUT_ROW_POSITION = 0;
const unsigned short INPUT_COL_POSITION = 1;
const unsigned short INPUT_DIRECTION_POSITION = 2;

typedef char board[BOARD_COL_SIZE][BOARD_ROW_SIZE];
typedef unsigned coordinate[COORDINATES_SIZE];

enum CellState {
  HOLE = 'O',
  PEG = '*',
  OUTBOUNDS = 'V'
};

enum Direction {
  UP = 'u',
  DOWN = 'd',
  RIGHT = 'r',
  LEFT = 'l'
};
#endif
