#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"
# include <string>

class ShrubberyCreationForm : public AForm {
private:
    std::string _target;
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();

    void  beExecuted() const;
};

#endif 
