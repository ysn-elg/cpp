#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat;

class Form {
private:
    const std::string   _name;
    bool                _isSigned;
    const int           _gradeToSign;
    const int           _gradeToExecute;
public:
    Form();
    Form(const std::string& name, const int gradeToSign, const int gradeToExecute);
    Form(const Form& other);
    ~Form();

    Form& operator=(const Form& other);

    const std::string&  getName()           const;
    bool                isSigned()          const;
    int                 getGradeToSign()    const;
    int                 getGradeToExecute() const;

    void  beSigned(Bureaucrat& obj);

    class GradeTooHighException : public std::exception {
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, Form& obj);

#endif
