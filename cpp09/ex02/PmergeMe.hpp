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
    // long              _timeToSortDeque;
    static std::size_t       _counter;
    
    // -- Parsing --
    bool isValidPositiveInt(const std::string& str) const;
    void parseArguments(int ac, char** av);

    // -- Vector sorting --
    void sortVector();
    std::vector<std::size_t> generateJacobsthal(std::size_t n);
    void mergeInsertSortVector(std::vector<int> &arr);

    // -- Compare + Counter -- 
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
    void displayBefore() const;
    void displayAfter() const;
    void displayTime() const;

    void isSorted(const std::vector<int>& vec) const;
    // static void counter() {
    //     ++_counter;
    // }
};

#endif
