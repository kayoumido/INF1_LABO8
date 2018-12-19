#ifndef LABO08_USERINPUT_H
#define LABO08_USERINPUT_H

#include "global.h"

bool isCommand(const std::string &input, const std::string &command);

bool isValidInput(const std::string &input);

bool isValidDirection(const char& direction);

#endif
