//
// Created by sebastian on 15/11/15.
//

#include <string>
#include <boost/algorithm/string.hpp>
#include <sstream>
#include "InputHandler.h"

std::vector<std::string> InputHandler::getUserInput() {
    std::string input;
    std::getline(std::cin, input);

    std::istringstream buffer(input);
    std::vector<std::string> ret{std::istream_iterator<std::string>{buffer},
                                 std::istream_iterator<std::string>{}};

    return ret;
}
