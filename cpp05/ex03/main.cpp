#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);

    AForm* f1 = someRandomIntern.makeForm("shrubbery creation", "home");
    AForm* f2 = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm* f3 = someRandomIntern.makeForm("presidential pardon", "Alice");
    AForm* f4 = someRandomIntern.makeForm("unknown form", "Nobody");

    try {
        if (f1) {
            boss.signForm(*f1);
            boss.executeForm(*f1);
        }
        if (f2) {
            boss.signForm(*f2);
            boss.executeForm(*f2);
        }
        if (f3) {
            boss.signForm(*f3);
            boss.executeForm(*f3);
        }
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    delete f1;
    delete f2;
    delete f3;
    delete f4;

    return 0;
}
