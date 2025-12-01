#include "Fixed.hpp"

const int Fixed::_bits= 8;

Fixed::Fixed( void ) : _number(0) {
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int number) {
    std::cout << "Int constructor called\n";
    _number = number << _bits;
}

Fixed::Fixed(const float number) {
    std::cout << "Float constructor called\n";
    _number = roundf(number * (1 << _bits));
}

Fixed::Fixed(const Fixed &copy) {
    std::cout << "Copy constructor called\n";
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &copy)
        this->_number = copy._number;
    return *this;
}

std::ostream& operator<<(std::ostream &cout, const Fixed &fixed)
{
    cout << fixed.toFloat();
    return cout;
}

Fixed::~Fixed( void ) {
    std::cout << "Destructor called\n";
}

int   Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called\n";
    return _number;
}

void  Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called\n";
    _number = raw;
}

float Fixed::toFloat( void ) const {
    return (float)_number/(float)(1 << _bits);
}

int   Fixed::toInt( void ) const {
   return  _number >> _bits;
}

