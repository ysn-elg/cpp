#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <ostream>
#include <string>

AForm::AForm() : _name("anonymous"), _isSigned(false)
             , _gradeToSign(1), _gradeToExecute(1) {}

AForm::AForm(const std::string& name, const int gradeToSign, const int gradeToExecute)
             : _name(name), _isSigned(false), _gradeToSign(gradeToSign)
             , _gradeToExecute(gradeToExecute) {
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
             : _name(other._name), _gradeToSign(other._gradeToSign)
             , _gradeToExecute(other._gradeToExecute) {}

AForm::~AForm() { }

AForm& AForm::operator=(const AForm& other) {
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

const std::string& AForm::getName()  const   { return _name; }
bool  AForm::isSigned()              const   { return _isSigned; }
int   AForm::getGradeToSign()        const   { return _gradeToSign; }
int   AForm::getGradeToExecute()     const   { return _gradeToExecute; }

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

void AForm::beSigned(Bureaucrat& obj) {
    if (obj.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const {
    
}

std::ostream& operator<<(std::ostream& os, AForm& obj) {
    os << "Form name: "         << obj.getName()            << ", "
       << "signed: "            << obj.isSigned()           << ", "
       << "grade to sign: "     << obj.getGradeToSign()     << ", "
       << "grade to execute: "  << obj.getGradeToExecute();
    return os;
}

