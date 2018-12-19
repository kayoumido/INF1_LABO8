#include "global.h"
#include <vector>
const std::string HELP_MESSAGE = "Deplacements possibles:";
const std::string ERROR_MESSAGE = "Deplacement invalide!";
const std::string PERFECT_MESSAGE = "Parfait, il ne reste qu'une bille au centre";
const std::string ALMOST_PERFECT_MESSAGE = "Bravo, vous avez gagne avec une seule bille restante. Au centre ce serait parfait";
const std::string NOT_BAD_MESSAGE = "Pas mal, il ne reste que ";
const std::string CAN_DO_BETTER_MESSAGE = "Vous pouvez faire mieux, il reste ";
const std::string PEG_TRANSLATION = "billes";



const std::string OUTBOUNDS_DISPLAY_VALUE = "  ";
const std::string HOLE_DISPLAY_VALUE = "..";
const char SPACE = ' ';
const unsigned short COL_WIDTH = 3;

void display(board);
void displayHelpMessage(std::vector<std::string> helpMoves);
void displayErrorMessage();
void displayEndGame(board board, unsigned nbPegsLeft);
std::string getDisplayValue(const board board, int row, int col);
