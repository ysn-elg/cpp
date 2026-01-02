#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("anonymous"), _grade(150) {
    std::cout << "Default constructor called!\n";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
                : _name(name), _grade(grade)
{
    std::cout << "Parametrized constructor called!\n";
    if (_grade > 150)
        ;
    else if (_grade < 1)
        ;
}

Bureaucrat::Bureaucrat(const Bureaucrat&other) : _name(other._name)

const std::string& Bureaucrat::getName() const { return _name; }
const int Bureaucrat::getName() const { return _grade; }


