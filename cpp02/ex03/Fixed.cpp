#include "Fixed.hpp"

const int Fixed::_bits= 8;

Fixed::Fixed( void ) : _number(0) { }

Fixed::Fixed(const int number) {
    _number = number << _bits;
}

Fixed::Fixed(const Fixed &copy) {
    *this = copy;
}

Fixed::Fixed(const float number) {
    _number = roundf(number * (1 << _bits));
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    if (this != &copy)
        this->_number = copy._number;
    return *this;
}

std::ostream& operator<<(std::ostream &cout, const Fixed &fixed)
{
    cout << fixed.toFloat();
    return cout;
}

Fixed::~Fixed( void ) { }

int   Fixed::getRawBits( void ) const {
    return _number;
}

void  Fixed::setRawBits(int const raw) {
    _number = raw;
}

float Fixed::toFloat( void ) const {
    return (float)_number/(float)(1 << _bits);
}

int   Fixed::toInt( void ) const {
   return  _number >> _bits;
}

/*   --- Comparison ---   */

bool  Fixed::operator==(const Fixed &other) const {
    if (this->_number == other._number)
        return true;
    return false;
}

bool  Fixed::operator>=(const Fixed &other) const {
    if (this->_number >= other._number)
        return true;
    return false;
}

bool  Fixed::operator<=(const Fixed &other) const {
    if (this->_number <= other._number)
        return true;
    return false;
}

bool  Fixed::operator>(const Fixed &other) const {
    if (this->_number > other._number)
        return true;
    return false;
}

bool  Fixed::operator<(const Fixed &other) const {
    if (this->_number < other._number)
        return true;
    return false;
}

bool  Fixed::operator!=(const Fixed &other) const {
    if (this->_number != other._number)
        return true;
    return false;
}

/*   --- Arithmetic operator ---   */

Fixed Fixed::operator*(const Fixed &other) const {
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator+(const Fixed &other) const {
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const {
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const {
    return (Fixed(this->toFloat() / other.toFloat()));
}

/*   --- increment - decrement ---   */

Fixed &Fixed::operator++() {
    _number++;
    return *this;
}

Fixed &Fixed::operator--() {
    _number--;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp = *this;
    _number++;
    return tmp;
}

Fixed Fixed::operator--(int) {
    Fixed tmp = *this;
    _number--;
    return tmp;
}

/*   --- min - max ---   */
Fixed &Fixed::min(Fixed &a, Fixed &b) {
    if (a < b)
        return a;
    return b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b) {
    if (a > b)
        return a;
    return b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    if (a < b)
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    if (a > b)
        return a;
    return b;
}

