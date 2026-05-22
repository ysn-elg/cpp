#ifndef   TYPES_HPP
# define  TYPES_HPP

#include <string>

enum Type {
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_SPECIAL,
    TYPE_INVALID
};

struct resultValues {
    char    c;
    int     i;
    float   f;
    double  d;
};

Type detection(const std::string& input);
resultValues getValues(const std::string& input, Type type);
void printResultes(resultValues &V);
void printImpossible();

#endif
