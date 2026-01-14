#ifndef   PRESIDENTIALPARDONFORM_HPP
# define  PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
    std::string target;
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string& name, const int gradeToSign, const int gradeToExecute);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();

    void  beExecuted() const;
}

#endif 
