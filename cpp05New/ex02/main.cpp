#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main () {
    
    AForm* f[] = {  new ShrubberyCreationForm("home") ,
                    new RobotomyRequestForm("RobotX") ,
                    new PresidentialPardonForm("President") };

    Bureaucrat boss("BOSS", 1);

    boss.signForm(*f[0]);
    boss.executeForm(*f[0]);

    std::cout << "---------------------------------------------\n";
    
    boss.signForm(*f[1]);
    boss.executeForm(*f[1]);

    std::cout << "---------------------------------------------\n";

    boss.signForm(*f[2]);
    boss.executeForm(*f[2]);
    
    delete f[0];
    delete f[1];
    delete f[2];
    
    return 0;
}
