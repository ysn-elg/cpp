#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);

        Form taxForm("Tax Form", 50, 20);

        std::cout << taxForm << std::endl;

        intern.signForm(taxForm);   // should fail
        boss.signForm(taxForm);     // should succeed

        std::cout << taxForm << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
