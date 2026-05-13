#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <ostream>
#include <string>

Form::Form() : _name("anonymous"), _isSigned(false)
             , _gradeToSign(1), _gradeToExecute(1) {}

Form::Form(const std::string& name, const int gradeToSign, const int gradeToExecute)
             : _name(name), _isSigned(false), _gradeToSign(gradeToSign)
             , _gradeToExecute(gradeToExecute) {
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
             : _name(other._name), _gradeToSign(other._gradeToSign)
             , _gradeToExecute(other._gradeToExecute) {}

Form::~Form() { }

Form& Form::operator=(const Form& other) {
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

const std::string& Form::getName()  const   { return _name; }
bool  Form::isSigned()              const   { return _isSigned; }
int   Form::getGradeToSign()        const   { return _gradeToSign; }
int   Form::getGradeToExecute()     const   { return _gradeToExecute; }

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

void Form::beSigned(Bureaucrat& obj) {
    if (obj.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

std::ostream& operator<<(std::ostream& os, Form& obj) {
    os << "Form name: "         << obj.getName()            << ", "
       << "signed: "            << obj.isSigned()           << ", "
       << "grade to sign: "     << obj.getGradeToSign()     << ", "
       << "grade to execute: "  << obj.getGradeToExecute();
    return os;
}

