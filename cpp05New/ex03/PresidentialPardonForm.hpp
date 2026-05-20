#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"
# include <string>

class PresidentialPardonForm : public AForm {
private:
    std::string _target;
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();

    void  beExecuted() const;
};

#endif 
