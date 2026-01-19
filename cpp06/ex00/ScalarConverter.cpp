#include "ScalarConverter.hpp"

/* -------------------------------------------------------- */

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &)
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &)
{
    return *this;
}

/* -------------------------------------------------------- */
parse

void ScalarConverter::convert(std::string& input) {
    Type type = detection(input); // first step: Detection
    if (type == TYPE_INVALID)
        ; // TODO: print impossible;
    value = parse(input, type);

}
