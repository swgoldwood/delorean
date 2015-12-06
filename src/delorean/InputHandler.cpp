//
// Created by sebastian on 15/11/15.
//

#include <string>
#include <boost/algorithm/string.hpp>
#include "InputHandler.h"

std::string InputHandler::getUserInput() {
    std::string input;
    std::getline(std::cin, input);

    boost::to_upper(input);

    std::cout << "input: " << input << std::endl;

    return input;
}
