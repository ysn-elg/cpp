#include "ScalarConverter.hpp"
#include "Types.hpp"

ScalarConverter::ScalarConverter() // private constructor? read more.
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


void ScalarConverter::convert(const std::string& input)
{
    Type type = detection(input);
    if (type == TYPE_INVALID) {
        printImpossible();
        return ;
    }
    resultValues V = getValues(input, type);
    printResultes(V);
}
