#ifndef LABO08_GLOBAL_H
#define LABO08_GLOBAL_H

const unsigned short BOARD_COL_SIZE = 7;
const unsigned short BOARD_ROW_SIZE = 7;
const unsigned short MARGIN = 2;
const unsigned short INITIAL_EMPTY_HOLE[] = {3, 3};
typedef char board[BOARD_COL_SIZE][BOARD_ROW_SIZE];

enum CellState {
    HOLE = 'O',
    PEG = '*',
    OUTBOUNDS = 'V'
};

enum Directions {
    UP = 'u',
    DOWN = 'd',
    RIGHT = 'r',
    LEFT = 'l'
};
#endif