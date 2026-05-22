#include "Types.hpp"
#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>

void printImpossible()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

static void printChar(resultValues &V)
{
    std::cout << "char: ";
    if (std::isnan(V.d) || std::isinf(V.d) ||
        V.d < std::numeric_limits<char>::min() ||
        V.d > std::numeric_limits<char>::max())
        std::cout << "impossible\n";
    else if (!std::isprint(static_cast<unsigned char>(V.c)))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << V.c << "'\n";
}

static void printInt(resultValues &V)
{
    std::cout << "int: ";
    if (std::isnan(V.d) || std::isinf(V.d) ||
        V.d < std::numeric_limits<int>::min() ||
        V.d > std::numeric_limits<int>::max())
    {
        std::cout << "impossible\n";
    }
    else
        std::cout << V.i << "\n";
}

static void printFloat(resultValues &V)
{
    std::cout << "float: ";
    if (std::isnan(V.d))
        std::cout << "nanf\n";
    else if (std::isinf(V.d) && V.d > 0)
        std::cout << ("+inff\n");
    else if (std::isinf(V.d) && V.d < 0)
        std::cout << ("-inff\n");
    else if (V.d > std::numeric_limits<float>::max()) 
        std::cout << "+inff\n";
    else
        std::cout << V.f << "f\n";
}

static void printDouble(resultValues &V)
{
    std::cout << "double: ";
    if (std::isnan(V.d))
        std::cout << "nan\n";
    else if (std::isinf(V.d) && V.d > 0)
        std::cout << ("+inf\n");
    else if (std::isinf(V.d) && V.d < 0)
        std::cout << ("-inf\n");
    else
        std::cout << V.d << std::endl;
}

void printResultes(resultValues &V)
{
    std::cout << std::fixed << std::setprecision(1);
    printChar(V);
    printInt(V);
    printFloat(V);
    printDouble(V);
}
