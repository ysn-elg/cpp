#include "PmergeMe.hpp"
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>

PmergeMe::PmergeMe() {}


PmergeMe::PmergeMe(const PmergeMe& other) {
    _vec = other._vec;
    _deq = other._deq;
}

PmergeMe &PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isValidPositiveInt(const std::string& str) const {
    if (str.empty())
        return false;

    for (std::size_t i = 0; i < str.size(); ++i) {
        if (!std::isdigit(str[i]))
            return false;
    }

    return true;
}

void PmergeMe::parseArguments(int ac, char** av) {
    if (ac < 2)
        throw std::runtime_error("Error");

    for (int i = 1; i < ac; ++i) {
        if (!isValidPositiveInt(av[i]))
            throw std::runtime_error("Error");

        int num = std::atoi(av[i]);
        _vec.push_back(num);
        _deq.push_back(num);
    }
}

void PmergeMe::displayBefore() const { // both
    std::cout << "Before: ";
    for (std::size_t i = 0; i < _vec.size(); ++i) {
        std::cout << _vec[i];
        if (i < _vec.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::displayAfter() const {
    std::cout << "After: ";
    for (std::size_t i = 0; i < _vec.size(); ++i) {
        std::cout << _vec[i];
        if (i < _vec.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::run(int ac, char** av) {
    parseArguments(ac, av);
    displayBefore();
    // TODO: sort using algo ...
    displayAfter();
}
