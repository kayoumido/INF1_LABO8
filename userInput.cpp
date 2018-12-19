#include <string>
#include "userInput.h"
#include <sstream>
#include <iostream>

std::string getUserInput() {
  std::string input;
  std::cin >> input;
  return input;
}

bool isValidInput(const std::string &input) {
  const unsigned short USER_INPUT_LENGTH = 3;

  if (input.length() != USER_INPUT_LENGTH) return false;

  unsigned coordinates = 0;
  std::stringstream ss(input);

  if (!(ss >> coordinates) and std::to_string(coordinates).length() != USER_INPUT_LENGTH - 1) return false;

  return isValidDirection(input.at(INPUT_DIRECTION_POSITION));
}

bool isValidDirection(const char &direction) {
  switch (direction) {
    case Directions::UP:
      break;
    case Directions::DOWN:
      break;
    case Directions::LEFT:
      break;
    case Directions::RIGHT:
      break;
    default:
      return false;
  }
  return true;
}

bool isCommand(const std::string &input, const std::string &command) {
  return input == command;
}

