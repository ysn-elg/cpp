#include "PmergeMe.hpp"
#include <algorithm>
#include <bits/types/struct_timeval.h>
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <iterator>
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

// ---------------- debugging -------------------
// static void printJacobsthal(std::string vecname, std::vector<std::size_t> jacobsthalOrder) {
//
//     // ----jacobsthal
//     std::cout << vecname << ": ";
//     for (std::size_t i = 0; i < jacobsthalOrder.size(); ++i) {
//         std::cout << jacobsthalOrder[i] << ((i != jacobsthalOrder.size() - 1) ? ", " : "");
//     }
//     std::cout << std::endl;
// }
// static void printResult(std::vector<int> result) {
//
//     std::cout << "result: ";
//     for (std::size_t i = 0; i < result.size(); ++i) {
//         std::cout << result[i] << ((i != result.size() - 1) ? ", " : "");
//     }
//     std::cout << std::endl;
// }
// static void printJacobsthal(std::vector<std::size_t> jacobsthalOrder) {
//
//     // ----jacobsthal
//     std::cout << "vec : ";
//     for (std::size_t i = 0; i < jacobsthalOrder.size(); ++i) {
//         std::cout << jacobsthalOrder[i] << ((i != jacobsthalOrder.size() - 1) ? ", " : "");
//     }
//     std::cout << std::endl;
// }
// ------------------- end -----------------------

void PmergeMe::sortVector() {
    timeval start;
    gettimeofday(&start, NULL); // TODO:

    mergeInsertSort(_vec);

    timeval end;
    gettimeofday(&end, NULL);

    long duration = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
    
    std::cout << "Time to process a range of " << _vec.size() 
              << " elements with std::vector : " << duration 
              << " us" << std::endl;
}

void PmergeMe::mergeInsertSort(std::vector<int> &arr) {
    std::vector<std::pair<int, int> > pairs;

    for (std::size_t i = 0; i + 1 < arr.size(); i += 2) { // func
        int a = arr[i];
        int b = arr[i + 1];
        
        if (a < b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }
    int oddElement = -1;
    if (arr.size() % 2)
        oddElement = arr[arr.size() - 1];

    std::vector<int> larger;

    for (std::size_t i = 0; i < pairs.size(); ++i)
        larger.push_back(pairs[i].second);
    
    if (larger.size() > 1)
        mergeInsertSort(larger);

    std::vector<int> pending;
    std::vector<bool> used(pairs.size(), false);
    
    for (size_t i = 0; i < larger.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (!used[j] && larger[i] == pairs[j].second) {
                pending.push_back(pairs[j].first);
                used[j] = true;
                break;
            }
        }
    }
            // 2 4 8 9     #2# 0 1
    std::vector<std::size_t> jacobsthalOrder;
    jacobsthalOrder = generateJacobsthal(larger.size());

    std::vector<int> result = larger;
  
    result.insert(result.begin(), pending[0]);
    for (std::size_t i = 1; i < jacobsthalOrder.size(); ++i)
    {
        std::size_t idx = jacobsthalOrder[i];
        std::vector<int>::iterator it = 
                        std::find(result.begin(), result.end(), larger[idx - 1]);
        std::size_t maxPos = std::distance(result.begin(), it);
        if (idx < pending.size() + 1) // not need to by handled
            binaryInsert(result, pending[idx - 1], maxPos + 1);
    }
    if (oddElement != -1)
        binaryInsert(result, oddElement, result.size());
    arr = result;
}

// insert 4 to [1 2 3 7 9] maxPos = 3 
// [1 2 3 4 5 6 7 8 9 10 12]   [1 3 5 7 9 11],   value = 11, maxPos = 11;
void PmergeMe::binaryInsert(std::vector<int> &arr, int value, std::size_t maxPos) {
    // std::size_t left = 0;
    int left = 0;
    int right = static_cast<int>(maxPos);
    while (left < right) {
        std::size_t mid = left + (right - left) / 2; // 1; 2; 2; 

        if (value < arr[mid]) { // 
            right = mid - 1; // 3; 3; 3;
        }
        else
            left = mid + 1; //  1; 2; 3;
    }
    arr.insert(arr.begin() + left, value);
}

std::vector<std::size_t> PmergeMe::generateJacobsthal(std::size_t n) { // TODO: for i = [0, 1, ...] if n != jacobsthal[i]?
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
    // printJacobsthal("jacobsthal", jacobsthal); // 0, 1, 1, 3, 5, 11 ..

    std::vector<std::size_t> order;
    order.push_back(1);

    for (std::size_t i = 3; i < jacobsthal.size(); ++i) {
        for (std::size_t j = jacobsthal[i]; j > jacobsthal[i - 1]; --j)
            order.push_back(j);
    }
    // printJacobsthal(order);
    return order;
}

void PmergeMe::run(int ac, char** av) {
    parseArguments(ac, av);
    displayBefore();
    
    sortVector();
    // TODO: sort using algo ...
    displayAfter();
}
