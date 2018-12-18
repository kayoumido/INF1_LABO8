#include "global.h"
#include <iostream>
#include <string>

const std::string OUTBOUNDS_DISPLAY_VALUE = "  ";
const char SPACE = ' ';
const std::string HOLE_DISPLAY_VALUE = "..";

void generate(board);
void display(board);
std::string getDisplayValue(const board board, int row, int col);
