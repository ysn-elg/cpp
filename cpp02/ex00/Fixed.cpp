#include "Fixed.hpp"

Fixed::Fixed( void ) : _number(0) {
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &copy) {
    std::cout << "Copy constructor called\n";
    *this = copy;
    //this->_number = copy._number; 
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &copy)
        this->_number = copy._number;
    return *this;
}

Fixed::~Fixed( void ) {
    std::cout << "Destructor called\n";
}

int   Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called\n";
    return _number;
}

void  Fixed::setRawBits(int const raw) {
    std::cout << "getRawBits member function called\n";
    _number = raw;
}

