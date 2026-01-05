#ifndef   FORM_HPP
# define  FORM_HPP

# include <string>
# include <ostream>
# include <exception>
// # include "Bureaucrat.hpp" // I can use class Bureaucrat; instaed
class Bureaucrat;

class Form {
private:
    const std::string _name;
    bool  _sign;
    const int _gradeToSign;
    const int _gradeToExecute;
public:
    Form();
    Form(const std::string& name, const int gradeToSign, const int gradeToExecute);
    Form(const Form& other);
    Form &operator=(const Form& other);
    ~Form();

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw(); 
    };
    
    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    const std::string& getName() const;
    bool  getSign() const;
    int   getGradeToSign() const;
    int   getGradeToExecute() const;

    void  beSigned(const Bureaucrat& obj);
};

std::ostream &operator<<(std::ostream &os, const Form& obj);

#endif
