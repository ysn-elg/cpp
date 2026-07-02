#include "PmergeMe.hpp"
#include <bits/types/struct_timeval.h>
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include <sys/time.h>
#include <utility>
#include <vector>

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

void PmergeMe::sortVector() {
    timeval start;
    gettimeofday(&start, NULL);

    mergeInsertSort(_vec, 0, _vec.size() - 1);

    timeval end;
    gettimeofday(&end, NULL);

    long duration = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_sec - start.tv_sec);
    
    std::cout << "Time to process a range of " << _vec.size() 
              << " elements with std::vector : " << duration 
              << " us" << std::endl;
}

void PmergeMe::mergeInsertSort(std::vector<int> &arr, int left, int right) {
    if (left >= right)
        return ;

    std::vector<std::pair<int, int> > pairs;

    for (int i = left; i < right; i += 2) { // i = 0,1; i = 2,3 #3
        int a = arr[i];
        int b = arr[i + 1];
        
        if (a < b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }
    int oddElement = -1;
    if (i == right)
        oddElement = arr[right];

    std::vector<int> larger;
    for (std::size_t i = 0; i < pairs.size(); ++i)
        larger.push_back(pairs[i].second);
    
    // if (oddElement == -1)
    //    chi haja;
    
    if (larger.size() > 1)
        mergeInsertSort(larger, 0, larger.size() - 1);

    std::vector<int> mainChain = larger;

    for (std::size_t i = 0; i < pairs.size(); ++i)
}

void PmergeMe::run(int ac, char** av) {
    parseArguments(ac, av);
    displayBefore();
    
    sortVector();
    // TODO: sort using algo ...
    displayAfter();
}
