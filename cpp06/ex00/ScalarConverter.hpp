#ifndef   SCALARCONVERTER_HPP
# define  SCALARCONVERTER_HPP

enum type {
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_SPECIAL,
    TYPE_INVALID
};

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter &operator=(const ScalarConverter& other);
    ~ScalarConverter();
public:
    static void convert(std::string &input);
}

#endif
