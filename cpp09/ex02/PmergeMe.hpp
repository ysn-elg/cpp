#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <cstddef>
#include <deque>
#include <vector>
#include <string>

class PmergeMe {
private:
    std::vector<int>  _vec;
    std::deque<int>   _deq;
    
    // -- Parsing --
    bool isValidPositiveInt(const std::string& str) const;
    void parseArguments(int ac, char** av);

    // -- Vector sorting --
    void sortVector();
    std::vector<std::size_t> generateJacobsthal(std::size_t n);
    void mergeInsertSort(std::vector<int> &arr);
    void binaryInsert(std::vector<int> &arr, int value, std::size_t maxPos);
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe &operator=(const PmergeMe& other);
    ~PmergeMe();

    void run(int ac, char** av);
    void displayBefore() const;
    void displayAfter() const;
};

#endif
