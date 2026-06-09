#include "Span.hpp"
#include <algorithm>
#include <stdexcept>

Span::Span() : _maxSize(0) { }
Span::Span(unsigned int maxSize) : _maxSize(maxSize) { }
Span::Span(const Span& other) : _maxSize(other._maxSize), V(other.V) { (void)other; }

Span &Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        V = other.V;
    }
    return *this;
}

Span::~Span() { }

void Span::addNumber(int num) {
    if (V.size() >= _maxSize)
        throw std::runtime_error("Span is full");
    V.push_back(num);
}

long Span::shortestSpan() const {
    if (V.size() < 2) {
        throw std::runtime_error("Not enough numbers");
    }

    std::vector<int> tmp = V;
    std::sort(tmp.begin(), tmp.end());

    long minSpan = longestSpan();
    for (size_t i = 1; i < tmp.size(); ++i) {
        long diff = static_cast<long>(tmp[i]) - static_cast<long>(tmp[i - 1]);
        if (diff < minSpan) {
            minSpan = diff;
        }
    }
    return minSpan;
}

long Span::longestSpan() const {
    if (V.size() < 2) {
        throw std::runtime_error("Not enough numbers");
    }

    long minVal = *std::min_element(V.begin(), V.end());
    long maxVal = *std::max_element(V.begin(), V.end());

    return maxVal - minVal;
}
