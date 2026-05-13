#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>
#include <iostream>
#include <ostream>
#include <string>

Bureaucrat::Bureaucrat() : _name("anonymous"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
                : _name(name), _grade(grade)
{
    if (_grade < 1)
        throw GradeTooHighException();
    if (_grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
                : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other)
        _grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    if (_grade < 2)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade > 149)
        throw GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(AForm& obj) {
    try {
        obj.beSigned(*this);
        std::cout << _name <<" signed " << obj.getName() << std::endl;
    }
    catch(const std::exception& e) {
        std::cout << _name          << " couldn’t sign "
                  << obj.getName()  << " because "
                  << e.what() << " (" << _grade << " lower than "
                  << obj.getGradeToSign() << " grade)." << std::endl;
    }
}

void  Bureaucrat::executeForm(AForm const & form) const {
    try {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch(std::exception& e) {
        std::cerr << _name << " couldn’t execute "
                  << form.getName()
                  << " because "
                  << e.what()
                  << std::endl; 
    }
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too high!";    
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too low!";    
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return os;
}
