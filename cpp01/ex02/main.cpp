#include <string>
#include <iostream>

int	main( void )
{
	std::string	const	str = "HI THIS IS BRAIN";
    std::string	const	*stringPTR = &str;
    std::string	const	&stringREF = str;

	std::cout   << "Memory addresses:\n"
				<< "  Address of string:\t\t" << &str << "\n"
				<< "  Address held by stringPTR:\t" << stringPTR << "\n"
				<< "  Address held by stringREF:\t"<< &stringREF << std::endl;

	std::cout   << "Values:\n"
				<< "  Value of string:\t\t\t" << str << "\n"
				<< "  Value pointed to by stringPTR:\t" << *stringPTR << "\n"
				<< "  Value pointed to by stringREF:\t"<< stringREF << std::endl;
	return 0;
}
