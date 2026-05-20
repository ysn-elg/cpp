#ifndef A_FORM_HPP
#define A_FORM_HPP

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat;

class AForm {
private:
    const std::string   _name;
    bool                _isSigned;
    const int           _gradeToSign;
    const int           _gradeToExecute;
public:
    AForm();
    AForm(const std::string& name, const int gradeToSign, const int gradeToExecute);
    AForm(const AForm& other);
    virtual ~AForm(); // TODO:

    AForm& operator=(const AForm& other);

    const std::string&  getName()           const;
    bool                isSigned()          const;
    int                 getGradeToSign()    const;
    int                 getGradeToExecute() const;

    void  beSigned(Bureaucrat& obj);
    void  execute(Bureaucrat const & executor) const; // TODO: New

    virtual void	beExecuted() const = 0; // TODO: New

    class GradeTooHighException : public std::exception {
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, AForm& obj);

#endif
