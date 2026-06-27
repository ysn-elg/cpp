#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <deque>
#include <vector>
#include <string>

class PmergeMe {
private:
    std::vector<int>  _vec;
    std::deque<int>   _deq;

    bool isValidPositiveInt(const std::string& str) const;
    void parseArguments(int ac, char** av);
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
