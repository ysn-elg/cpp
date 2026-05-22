#include "Types.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>

static bool isSpecial(const std::string& input) {
    return (input == "nan"  || input == "nanf" ||
            input == "+inf" || input == "-inf" ||
            input == "+inff"|| input == "-inff");
}

Type detection(const std::string& input) {
    if (input.empty())
        return TYPE_INVALID;
    if (isSpecial(input))
        return TYPE_SPECIAL;
    if (input.length() == 1 && !std::isdigit(input[0]))
        return TYPE_CHAR;
    bool hasDot = false, hasF = false;
    size_t i = 0;
    if (input[0] == '+' || input[0] == '-')
        i++;
    if (i == input.length())
        return TYPE_INVALID;
    for(; i < input.length(); i++) {
        if (std::isdigit(input[i]))
            continue ;
        else if (input[i] == '.' && !hasDot)
            hasDot = true;
        else if (input[i] == 'f' && i == input.length() - 1)
            hasF = true;
        else
            return TYPE_INVALID;
    }
    if (hasDot && hasF)
        return TYPE_FLOAT;
    if (hasDot)
        return TYPE_DOUBLE;
    if (hasF)
        return TYPE_INVALID;

    if (std::strtod(input.c_str(), NULL) > std::numeric_limits<int>::max()
        || std::strtod(input.c_str(), NULL) < std::numeric_limits<int>::min())
        return TYPE_DOUBLE;
    return TYPE_INT;
}
