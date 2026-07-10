#include "PmergeMe.hpp"
#include <algorithm>
#include <bits/types/struct_timeval.h>
#include <cassert>
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <sys/time.h>
#include <utility>
#include <vector>

std::size_t PmergeMe::_counter = 0;

PmergeMe::PmergeMe() {}


PmergeMe::PmergeMe(const PmergeMe& other) {
    _vec = other._vec;
    _deq = other._deq;
    // _counter = other._counter;
}

PmergeMe &PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vec = other._vec;
        _deq = other._deq;
        // _counter = other._counter;
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
        if (i < _deq.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

// --- parsing end ---

std::vector<std::size_t> PmergeMe::generateJacobsthal(std::size_t n) {
    if (n == 0)
        return std::vector<std::size_t>();

    std::vector<std::size_t> jacobsthal;

    jacobsthal.push_back(0);
    jacobsthal.push_back(1);

    while (jacobsthal.back() < n) {
        std::size_t next = jacobsthal[jacobsthal.size() - 1] +
                            2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(next);
    }
    if (jacobsthal.back() != n)
        jacobsthal.back() = n;

    std::vector<std::size_t> order;
    order.push_back(1);

    for (std::size_t i = 3; i < jacobsthal.size(); ++i) {
        for (std::size_t j = jacobsthal[i]; j > jacobsthal[i - 1]; --j)
            order.push_back(j);
    }
    return order;
}

// -- deque --

void PmergeMe::mergeInsertSortDeque(std::deque<int> &arr) {
    std::deque<std::pair<int, int> > pairs;

    for (std::size_t i = 0; i + 1 < arr.size(); i += 2) { // func
        int a = arr[i];
        int b = arr[i + 1];
        
        if (a < b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
        ++_counter;
    }
    int oddElement = -1;
    if (arr.size() % 2)
        oddElement = arr[arr.size() - 1];

    std::deque<int> larger;

    for (std::size_t i = 0; i < pairs.size(); ++i)
        larger.push_back(pairs[i].second);

    if (larger.size() > 1)
        mergeInsertSortDeque(larger);

    std::deque<std::pair<int, int> > sortedPairs;
    std::deque<bool> used(pairs.size(), false);
    
    for (size_t i = 0; i < larger.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (!used[j] && larger[i] == pairs[j].second) {
                sortedPairs.push_back(pairs[j]);
                used[j] = true;
                break;
            }
        }
    }

    std::vector<std::size_t> jacobsthalOrder = generateJacobsthal(larger.size() + (oddElement != -1));

    larger.insert(larger.begin(), sortedPairs[0].first);

    for (std::size_t i = 1; i < jacobsthalOrder.size(); ++i)
    {
        std::size_t idx = jacobsthalOrder[i];
        if (oddElement != -1 && idx == jacobsthalOrder.size())
        {
            std::deque<int>::iterator pos =
                                std::lower_bound(larger.begin(), larger.end(), oddElement, comp);
            larger.insert(pos, oddElement);
            continue;
        }
        int small = static_cast<int>(sortedPairs[idx - 1].first);
        int large = static_cast<int>(sortedPairs[idx - 1].second);

        std::deque<int>::iterator it = std::find(larger.begin(), larger.end(), large);
        std::deque<int>::iterator pos = std::lower_bound(larger.begin(), it, small, comp);

        larger.insert(pos, small);
    }

    arr = larger;
}
// -------------------------------------------------------------

void PmergeMe::mergeInsertSortVector(std::vector<int> &arr) {
    std::vector<std::pair<int, int> > pairs;

    for (std::size_t i = 0; i + 1 < arr.size(); i += 2) { // func
        int a = arr[i];
        int b = arr[i + 1];
        
        if (a < b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
        ++_counter;
    }
    int oddElement = -1;
    if (arr.size() % 2)
        oddElement = arr[arr.size() - 1];

    std::vector<int> larger;

    for (std::size_t i = 0; i < pairs.size(); ++i)
        larger.push_back(pairs[i].second);

    if (larger.size() > 1)
        mergeInsertSortVector(larger);

    std::vector<std::pair<int, int> > sortedPairs;
    std::vector<bool> used(pairs.size(), false);
    
    for (size_t i = 0; i < larger.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (!used[j] && larger[i] == pairs[j].second) {
                sortedPairs.push_back(pairs[j]);
                used[j] = true;
                break;
            }
        }
    }

    std::vector<std::size_t> jacobsthalOrder = generateJacobsthal(larger.size() + (oddElement != -1));

    larger.insert(larger.begin(), sortedPairs[0].first);

    for (std::size_t i = 1; i < jacobsthalOrder.size(); ++i)
    {
        std::size_t idx = jacobsthalOrder[i];
        if (oddElement != -1 && idx == jacobsthalOrder.size())
        {
            std::vector<int>::iterator pos =
                                std::lower_bound(larger.begin(), larger.end(), oddElement, comp);
            larger.insert(pos, oddElement);
            continue;
        }
        int small = static_cast<int>(sortedPairs[idx - 1].first);
        int large = static_cast<int>(sortedPairs[idx - 1].second);
        
        std::vector<int>::iterator it = std::find(larger.begin(), larger.end(), large);
        std::vector<int>::iterator pos = std::lower_bound(larger.begin(), it, small, comp);

        larger.insert(pos, small);
    }

    arr = larger;
}

void PmergeMe::sortVector() {
    timeval start;
    gettimeofday(&start, NULL); // TODO:

    if (_vec.size() > 1)
        mergeInsertSortVector(_vec);

    timeval end;
    gettimeofday(&end, NULL);

    _timeToSortVector = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
}

void PmergeMe::sortDeque() {
    timeval start;
    gettimeofday(&start, NULL); // TODO:

    if (_vec.size() > 1)
        mergeInsertSortDeque(_deq);

    timeval end;
    gettimeofday(&end, NULL);

    _timeToSortDeque = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
}

void PmergeMe::displayTime() const
{
    std::cout << "Time to process a range of " << _vec.size() 
              << " elements with std::vector : " << _timeToSortVector 
              << " us" << std::endl;

    std::cout << "Time to process a range of " << _deq.size() 
              << " elements with std::deque : " << _timeToSortDeque 
              << " us" << std::endl;
}

void PmergeMe::run(int ac, char** av) {
    parseArguments(ac, av);
    displayBefore();
    sortVector();
    _n = _counter;
    _counter = 0;
    sortDeque();
    displayAfter();
    displayTime();
    isSorted();
}

void PmergeMe::isSorted() const
{
    for (std::size_t i = 1; i < _vec.size(); ++i)
    {
        if (_vec[i - 1] > _vec[i]) {
                std::cout << "(vec) Not Sorted\n";
            return;
        }
    }
    for (std::size_t i = 1; i < _deq.size(); ++i)
    {
        if (_deq[i - 1] > _deq[i]) {
                std::cout << "(deq) Not Sorted\n";
            return;
        }
    }
    std::cout << "Sorted\n"
              << "Vector counter = " << _n << "\n"
              << "Deque counter = " << _counter << "\n";
}
