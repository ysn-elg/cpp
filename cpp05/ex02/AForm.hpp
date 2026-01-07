#ifndef   AFORM_HPP
# define  AFORM_HPP

# include <string>
# include <ostream>
# include <exception>

class Bureaucrat;

class AForm {
private:
    const std::string _name;
    bool  _sign;
    const int _gradeToSign;
    const int _gradeToExecute;
public:
    AForm();
    AForm(const std::string& name, const int gradeToSign, const int gradeToExecute);
    AForm(const AForm& other);
    AForm &operator=(const AForm& other);
    virtual ~AForm();

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

std::ostream &operator<<(std::ostream &os, const AForm& obj);

#endif
