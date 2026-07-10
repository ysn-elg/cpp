
#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <cctype>
#include <cstdlib>

RPN::RPN() {}

RPN::~RPN() {
    while (!_stack.empty())
        _stack.pop();
}

RPN::RPN(const RPN &other) : _stack(other._stack) {}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other) {
        while (!_stack.empty())
            _stack.pop();
        _stack = other._stack;
    }
    return *this;
}

void RPN::applyOperation(char op) {
    if (_stack.size() < 2)
        throw std::runtime_error("Error");

    int b = _stack.top();
    _stack.pop();
    int a = _stack.top();
    _stack.pop();
    int result;

    switch (op) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if (b == 0)
                throw std::runtime_error("Error");
            result = a / b;
            break;
        default:
            throw std::runtime_error("Error");
    }
    _stack.push(result);
}

int RPN::evaluate(const std::string &expression) {
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token) {
        if (token.length() > 1)
            throw std::runtime_error("Error");
        if (std::isdigit(token[0]))
            _stack.push(token[0] - '0');
        else if (token == "+" || token == "-" || token == "/" || token == "*")
            applyOperation(token[0]);
        else
            throw std::runtime_error("Error");
    }
    
    if (_stack.size() != 1)
        throw std::runtime_error("Error");
    
    return _stack.top();
}
