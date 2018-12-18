#ifndef LABO08_TYPEDEF_H
#define LABO08_TYPEDEF_H

const unsigned short BOARD_COL_SIZE = 7;
const unsigned short BOARD_ROW_SIZE = 7;

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
