#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("anonymous"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{ }

Form::Form(const std::string& name, const int gradeToSign, const int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
    else if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw GradeTooHighException();
}

Form::Form(const Form& other) 
    : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{ }

Form &Form::operator=(const Form& other)
{
    if (this != &other)
        _signed = other._signed;
    return *this;
}

Form::~Form() { }

const std::string& Form::getName() const { return _name; }
bool  Form::getSign() const { return _signed; }
int   Form::getGradeToSign() const { return _gradeToSign; }
int   Form::getGradeToExecute() const { return _gradeToExecute; }

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

void  Form::beSigned(const Bureaucrat& obj)
{
    if (obj.getGrade() > _gradeToSign)
        throw Form::GradeTooLowException(); // TODO: does scope importent here!?
    _signed = true;
}

std::ostream &operator<<(std::ostream &os, const Form& obj)
{
    os << "Form name: " << obj.getName() << ", "
       << "signed: " << obj.getSign() << ", "
       << "grade to sign: " << obj.getGradeToSign() << ", "
       << "grade to execute: " << obj.getGradeToExecute();
    return os;
}


