#include "Form.hpp"

Form::Form() : _name("anonymous"), _sign(false), _gradeToExecute(150), _gradeToSign(150)
{ }

Form(const std::string& name, const int gradeToSign, const int gradeToExecute)
    : _name(name), _sign(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{ }

Form(const Form& other) 
    : _name(other._name), _sign(other._sign), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{ }

Form &Form::operator=(const Form& other)
{
    if (this != &other)
        _sign = other._sign;
    return *this;
}

Form::~Form() { }

const std::string& Form::getName() const { return _name; }
bool  Form::getSign() const { return _sign; }
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

void  Form::beSigned(const Bureaucrat& obj) {
    if (obj._grade > _gradeToSign)
        Throw Form::GradeTooLowException();
    _sign = true;
}


