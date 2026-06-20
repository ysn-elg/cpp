#ifndef R_P_N_HPP
#define R_P_N_HPP

#include <string>
#include <stack>

class RPN {
private:
    std::stack<int> _stack;

    void applyOperation(char op);

public:
    RPN();
    ~RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);

    int evaluate(const std::string &expression);
};

#endif
