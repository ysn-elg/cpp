#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat a("Alice", 2);
        std::cout << a << std::endl;

        a.incrementGrade();   /* should become grade 1 */
        std::cout << a << std::endl;

        a.incrementGrade();   /* should throw */
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "------------------------------------------" << std::endl;

    try
    {
        Bureaucrat b("Bob", 200); /* invalid → throws */
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

