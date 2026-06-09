#include <exception>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Span.hpp"

int main() // Exp
{
    try {
        std::cout << "---- Subject tests ----" << std::endl;
	    Span sp = Span(5);
	    sp.addNumber(6);
	    sp.addNumber(3);
	    sp.addNumber(17);
	    sp.addNumber(9);
	    sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "----- Own tests ------" << std::endl;
        std::srand(std::time(0));
        Span              sp(10000);

        std::vector<int>  v;

        for (int i = 0; i < 10000; i++)
            v.push_back(std::rand());

        sp.addNumbers(v.begin(), v.end());

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
