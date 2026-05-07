#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    std::cout << "---- invalid high grade on construction ----" << std::endl;
    try
    {
        Bureaucrat a("Alice", 0);
        std::cout << a << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n---- invalid low grade on construction ----" << std::endl;
    try
    {
        Bureaucrat b("Bob", 151);
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n---- increment test ----" << std::endl;
    try
    {
        Bureaucrat c("Charlie", 2);
        std::cout << c << std::endl;
        c.incrementGrade();
        std::cout << c << std::endl;
        c.incrementGrade();
        std::cout << "We will not see this message";
        std::cout << c << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n---- decrement test ----" << std::endl;
    try
    {
        Bureaucrat d("David", 149);
        std::cout << d << std::endl;
        d.decrementGrade();
        std::cout << d << std::endl;
        d.decrementGrade();
        std::cout << d << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
