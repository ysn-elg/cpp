#ifndef   FORM_HPP
# define  FORM_HPP

# include <string>
# include <ostream>
# include <exception>
# include "Bureaucrat.hpp"

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




/////////////////////////////////////////////////////////////////////
void Bureaucrat::signForm(Form& obj) const
{
    try
    {
        obj.beSigned(*this); // Attempt to sign the form
        std::cout << getName() << " signed " << obj.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << getName() << " couldn’t sign " 
                  << obj.getName() << " because " 
                  << e.what() << std::endl;
    }
}
//////////////////////////////////////////////////////////////////////
