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
    long              _timeToSortVector;
    long              _timeToSortDeque;
    static std::size_t       _counter;
    std::size_t       _n;
    
    // -- Parsing --
    bool isValidPositiveInt(const std::string& str) const;
    void parseArguments(int ac, char** av);

    // -- Before After --
    void displayBefore() const;
    void displayAfter() const;
    
    // -- Jacobsthal --
    std::vector<std::size_t> generateJacobsthal(std::size_t n);

    // -- Vector sorting --
    void sortVector();
    void mergeInsertSortVector(std::vector<int> &arr);

    // -- Vector sorting --
    void sortDeque();
    void mergeInsertSortDeque(std::deque<int> &arr);


    // -- Timer --
    void displayTime() const;

    // -- Compare & Counter -- 
    static bool comp(int a, int b) {
        ++_counter;
        return a < b;
    }

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe &operator=(const PmergeMe& other);
    ~PmergeMe();

    void run(int ac, char** av);

    void isSorted() const;
};

#endif
