/**
 * @file userInput.h
 * @brief This file contains the function that check the input of the user
*/

#ifndef LABO08_USERINPUT_H
#define LABO08_USERINPUT_H

#include "global.h"

/**
 * @brief ask for user input
 * @return the value given by the user
 */
std::string getUserInput();

/**
 * @brief check if the user input is a special command
 * @example q for quit, h for help
 *
 * @param input command given by the user
 * @param command the possible command to xecute
 * @return
 */
bool isCommand(const std::string &input, const std::string &command);

/**
 * @brief check if the user input is valid. i.e. composed of two digits and an alpha
 * @param input to validate
 * @return
 */
bool isValidInput(const std::string &input);

/**
 * @brief check the direction(l,r,d,u)
 *
 * @param direction
 * @return
 */
bool isValidDirection(const char &direction);

#endif
