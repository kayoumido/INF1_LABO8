#ifndef LABO08_USERINPUT_H
#define LABO08_USERINPUT_H

#include "global.h"

/**
 * @brief check if the user input is a special command
 * @example q for quit, h for help
 * @param input
 * @param command
 * @return
 */
bool isCommand(const std::string &input, const std::string &command);

/**
 * @brief check if the user input
 * @param input
 * @return
 */
bool isValidInput(const std::string &input);

/**
 *
 * @brief check the direction(l,r,d,u)
 * @param direction
 * @return
 */
bool isValidDirection(const char &direction);

#endif
