/**
* @file global.h
* @brief This file contains all the settings of the board disposition, cell state and directions.
*/

#ifndef LABO08_GLOBAL_H
#define LABO08_GLOBAL_H
/** 
 * Board column size
*/
const unsigned short BOARD_COL_SIZE = 7;
/** 
 * Board row size
*/
const unsigned short BOARD_ROW_SIZE = 7;
/** 
 * Board margin
*/
const unsigned short MARGIN = 2;
/** 
 * Initial empty hole
*/
const unsigned short INITIAL_EMPTY_HOLE[] = {3, 3};
/** 
 * Coordinates size
*/
const unsigned short COORDINATES_SIZE = 2;
/** 
 * Row-only coordinates
*/
const unsigned short I_COORDINATE = 0;
/** 
 * Column-only coordinates
*/
const unsigned short J_COORDINATE = 1;
/** 
 * Input row position
*/
const unsigned short INPUT_ROW_POSITION = 0;
/** 
 * Input column size
*/
const unsigned short INPUT_COL_POSITION = 1;
/** 
 * Input direction position
*/

const unsigned short INPUT_DIRECTION_POSITION = 2;
/** 
 * Define a new type "board" that contain a multidimensionnal array with the variables numbers of row and column
*/

typedef char board[BOARD_COL_SIZE][BOARD_ROW_SIZE];

/** 
 * Define a new type "coordoinates" that contain an array with all the coordinates
*/
typedef unsigned coordinate[COORDINATES_SIZE];

/** 
 * Cell state (hole, peg, or outbounds)
*/
enum CellState {
    HOLE = 'O',
    PEG = '*',
    OUTBOUNDS = 'V'
};

/** 
 * Direction (up, down, right, left)
*/
enum Direction {
    UP = 'u',
    DOWN = 'd',
    RIGHT = 'r',
    LEFT = 'l'
};
#endif
