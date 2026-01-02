#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("anonymous"), _grade(150)
{
    std::cout << "Default constructor called!\n";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
                : _name(name), _grade(grade)
{
    std::cout << "Parametrized constructor called!\n";
    if (_grade > 150)
        throw GradeTooLowException();
    else if (_grade < 1)
        throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat&other)
            : _name(other._name), _grade(other._grade)
{
    std::cout << "Copy constructor called!\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "Copy assignement operator called!\n";
    if (this != &other)
        _grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor called!\n";
}

const std::string& Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade()
{
    if (this->_grade > 1)
        this->_grade--;
    else
        throw GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade < 150)
        this->_grade++;
    else
        throw GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too hight!\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low!\n";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj) // check it again !!
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return os;
}
