#ifndef   ROBOTOMYREQUESTFORM_HPP
# define  ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
    std::string target;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& name, const int gradeToSign, const int gradeToExecute);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();
}

#endif 
