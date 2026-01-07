#include "AAForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("anonymous"), _sign(false), _gradeToSign(150), _gradeToExecute(150)
{ }

AForm::AForm(const std::string& name, const int gradeToSign, const int gradeToExecute)
    : _name(name), _sign(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (_gradeToExecute > 150 || _gradeToSign > 150)
        throw GradeTooLowException();
    else if (_gradeToExecute < 1 || _gradeToSign < 1)
        throw GradeTooHighException();
}

AForm::AForm(const AForm& other) 
    : _name(other._name), _sign(other._sign), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{ }

AForm &AForm::operator=(const AForm& other)
{
    if (this != &other)
        _sign = other._sign;
    return *this;
}

AForm::~AForm() { }

const std::string& AForm::getName() const { return _name; }
bool  AForm::getSign() const { return _sign; }
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

void  AForm::beSigned(const Bureaucrat& obj) {
    if (obj.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();
    _sign = true;
}

std::ostream &operator<<(std::ostream &os, const AForm& obj)
{
    os << "AForm name: " << obj.getName() << ", "
       << "signed: " << obj.getSign() << ", "
       << "grade to sign: " << obj.getGradeToSign() << ", "
       << "grade to execute: " << obj.getGradeToExecute();
    return os;
}

