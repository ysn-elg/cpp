#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    Bureaucrat boss("Boss", 1);

    AForm* f1 = new ShrubberyCreationForm("home");
    AForm* f2 = new RobotomyRequestForm("Bender");
    AForm* f3 = new PresidentialPardonForm("Arthur");
    std::cout << "------------------------------------------------------\n";
    std::cout << "ShrubberyCreationForm test -> outfile: home_shrubbery\n";
    std::cout << "------------------------------------------------------\n";
    boss.signForm(*f1);
    boss.executeForm(*f1);
    std::cout << "------------------------------------------------------\n";
    std::cout << "             RobotomyRequestForm test:\n";
    std::cout << "------------------------------------------------------\n";
    boss.signForm(*f2);
    boss.executeForm(*f2);
    std::cout << "------------------------------------------------------\n";
    std::cout << "            PresidentialPardonForm test:\n";
    std::cout << "------------------------------------------------------\n";
    boss.signForm(*f3);
    boss.executeForm(*f3);

    delete f1;
    delete f2;
    delete f3;

    return 0;
}
