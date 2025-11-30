#include "Point.hpp"

Point::Point() : x(0), y(0) { }

Point::Point(const Fixed X, const Fixed Y) : x(X), y(Y) { }

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point &Point::operator=(const Point &) {
    return *this;
}

bool Point::operator==(const Point &other) const {
    if (this->GetX().toFloat() == other.GetX().toFloat()
        && this->GetY().toFloat() == other.GetY().toFloat())
       return true;
    return false;
}

Fixed Point::GetX() const { return x; }

Fixed Point::GetY() const { return y; }

Point::~Point() { }

