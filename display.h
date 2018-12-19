#include "global.h"

const std::string OUTBOUNDS_DISPLAY_VALUE = "  ";
const std::string HOLE_DISPLAY_VALUE = "..";
const char SPACE = ' ';
const unsigned short COL_WIDTH = 3;

void generate(board);
void display(board);
std::string getDisplayValue(const board board, int row, int col);
