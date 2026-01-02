
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat b1; // default constructor
        std::cout << b1;

        Bureaucrat b2("Alice", 2); // parametrized constructor
        std::cout << b2;

        // incrementGrade test
        b2.incrementGrade(); // grade should go from 2 → 1
        std::cout << "After increment: " << b2;

        // this should throw GradeTooHighException
        b2.incrementGrade(); 
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b3("Bob", 150);
        std::cout << b3;

        // decrementGrade test
        b3.decrementGrade(); // grade should go from 150 → 151 → should throw
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    // copy constructor and assignment operator test
    Bureaucrat original("Charlie", 75);
    Bureaucrat copy(original); // copy constructor
    std::cout << "Copy: " << copy;

    Bureaucrat assigned;
    assigned = original; // copy assignment
    std::cout << "Assigned: " << assigned;

    return 0;
}
