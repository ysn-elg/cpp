#include "Harl.hpp"

int main()
{
	Harl harl;
    std::cout << "\033[1;32m1------↴\033[0m\n";
	harl.complain("INFO");
    std::cout << "\033[1;32m\n2------↴\033[0m\n";
	harl.complain("WARNING");
    std::cout << "\033[1;32m\n3------↴\033[0m\n";
	harl.complain("DEBUG");
    std::cout << "\033[1;32m\n4------↴\033[0m\n";
	harl.complain("ERROR");
    std::cout << "\033[1;32m\n5------↴\033[0m\n";
    harl.complain("random");
    return 0;
}
