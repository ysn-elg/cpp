#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("anonymous"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{ }

AForm::AForm(const std::string& name, const int gradeToSign, const int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
    else if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw GradeTooHighException();
}

AForm::AForm(const AForm& other) 
    : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{ }

AForm &AForm::operator=(const AForm& other)
{
    if (this != &other)
        _signed = other._signed;
    return *this;
}

AForm::~AForm() { }

const std::string& AForm::getName() const { return _name; }
bool  AForm::getSign() const { return _signed; }
int   AForm::getGradeToSign() const { return _gradeToSign; }
int   AForm::getGradeToExecute() const { return _gradeToExecute; }

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

void  AForm::beSigned(const Bureaucrat& obj)
{
    if (obj.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();
    _signed = true;
}

std::ostream &operator<<(std::ostream &os, const AForm& obj)
{
    os << "AForm name: " << obj.getName() << ", "
       << "signed: " << obj.getSign() << ", "
       << "grade to sign: " << obj.getGradeToSign() << ", "
       << "grade to execute: " << obj.getGradeToExecute();
    return os;
}


