#include "Types.hpp"
#include <cstdlib>
#include <limits>


static resultValues convertToActualType(const std::string& input, Type type)
{
    resultValues V;
    if      (type == TYPE_CHAR)     V.c = input[0];
    else if (type == TYPE_INT)      V.i = static_cast<int>(std::strtol(input.c_str(), NULL, 10)); 
    else if (type == TYPE_FLOAT)    V.f = std::strtof(input.c_str(), NULL);
    else if (type == TYPE_DOUBLE)   V.d = std::strtod(input.c_str(), NULL);
    else if (type == TYPE_SPECIAL)
    {
        if (input == "nan" || input == "nanf")
            V.d = std::numeric_limits<double>::quiet_NaN();
        else if (input[0] == '-')
            V.d = -std::numeric_limits<double>::infinity();
        else
            V.d = std::numeric_limits<double>::infinity();
        return V;
    }
    return V;
}

static void convertRestOfTypes(resultValues& V, Type type)
{
    if (type == TYPE_CHAR) {
        V.i = static_cast<int>(V.c);
        V.f = static_cast<float>(V.c);
        V.d = static_cast<double>(V.c);
    }
    else if (type == TYPE_INT) {
        V.c = static_cast<char>(V.i);
        V.f = static_cast<float>(V.i);
        V.d = static_cast<double>(V.i);
    }
    else if (type == TYPE_FLOAT) {
        V.c = static_cast<char>(V.f);
        V.i = static_cast<int>(V.f);
        V.d = static_cast<double>(V.f);
    }
    else if (type == TYPE_DOUBLE || type == TYPE_SPECIAL) {
        V.c = static_cast<char>(V.d);
        V.i = static_cast<int>(V.d);
        V.f = static_cast<float>(V.d);
    }
}


resultValues getValues(const std::string& input, Type type)
{
    resultValues V = convertToActualType(input, type);
    convertRestOfTypes(V, type);
    return V;
}
