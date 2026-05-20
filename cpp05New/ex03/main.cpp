
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>

int main()
{
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);

    AForm* f1 = someRandomIntern.makeForm("shrubbery creation", "home");
    AForm* f2 = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm* f3 = someRandomIntern.makeForm("presidential pardon", "Alice");
    AForm* unknown = someRandomIntern.makeForm("unknown form", "Nobody");
    
    std::cout << std::endl;

    try {
        if (f1) {
            boss.signForm(*f1);
            boss.executeForm(*f1);
            std::cout << std::endl;
        }
        if (f2) {
            boss.signForm(*f2);
            boss.executeForm(*f2);
            std::cout << std::endl;
        }
        if (f3) {
            boss.signForm(*f3);
            boss.executeForm(*f3);
            std::cout << std::endl;
        }
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    delete f1;
    delete f2;
    delete f3;
    delete unknown;

    return 0;
}
