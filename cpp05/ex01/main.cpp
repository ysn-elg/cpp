#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    Bureaucrat  A("[A]", 99);
    Bureaucrat  B("[B]", 10);
    Form        F("[F]", 13, 37);

    std::cout << A << std::endl;
    std::cout << B << std::endl;
    std::cout << F << std::endl;

    std::cout << std::endl;
    A.signForm(F);              /*   should  fail   */
    std::cout << F << std::endl;

    std::cout << std::endl;
    B.signForm(F);              /*  should succeed  */
    std::cout << F << std::endl;
}
