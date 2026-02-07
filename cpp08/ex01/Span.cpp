#include "Span.hpp"

Span::Span() : _stored(0),_shortestSpan(0), _longestSpan(0), _updated(0) { }
Span::Span(int stored) : _stored(stored),_shortestSpan(0), _longestSpan(0), _updated(0) { }
Span::Span(const Span& other) :
    _stored(other._stored),_shortestSpan(other._shortestSpan),
    _longestSpan(other._longestSpan), _updated(other._updated)
{
    (void)other;
}

Span &Span::operator=(const Span& other) {
    if (this != &other) {
        _stored = other._stored;
        _shortestSpan = other._shortestSpan;
        _longestSpan = other._longestSpan;
        _updated = other._updated;
    }
    return *this;
}
