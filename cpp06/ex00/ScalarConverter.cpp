#include "ScalarConverter.hpp"


static void detection(std::string& input) {
    // TODO: if else...
}

void ScalarConverter::convert(std::string& input) {
    type = detection(input); // first step: Detection
    if (type == TYPE_INVALID)
        ; // TODO: print impossible;
    value = parse(input, type);

}
