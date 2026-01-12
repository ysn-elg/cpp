#include "Bureaucrat.hpp"
#include <iostream>


int main()
{
    std::cout << "----- Catch exception at creation of object -----\n";
    try {
        Bureaucrat A("a", 0);
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n----- Catch exception by decrement the grade -----\n";
    try {
        Bureaucrat B("b", 149);
        std::cout << B << std::endl;

        B.decrementGrade(); /* become 150 */
        std::cout << B << std::endl;
        
        B.decrementGrade(); /* become 151 => should throw an exception */
        std::cout << B << std::endl;

        std::cout << "We cannot see this message";
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}
