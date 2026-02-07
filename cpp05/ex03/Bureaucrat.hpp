#ifndef   BUREAUCRAT_HPP
# define  BUREAUCRAT_HPP

# include <string>
# include <exception>

class AForm;

class Bureaucrat {
private:
    const std::string _name;
    int   _grade;
public:
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    ~Bureaucrat();
    
    Bureaucrat &operator=(const Bureaucrat& other);    
    
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    const std::string getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    void signForm(AForm &obj);

    void executeForm(AForm const & form) const;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat& obj);

#endif
