#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <ostream>
#include <string>

class AForm;

class Bureaucrat {
private:
    const std::string _name;
    int _grade;
public:
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat& other);

    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    const std::string&  getName()   const;
    int                 getGrade()  const;

    void  incrementGrade();
    void  decrementGrade();

    void  signForm(AForm & obj);
    void  executeForm(AForm const & form) const; // New

    class GradeTooHighException : public std::exception {
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
