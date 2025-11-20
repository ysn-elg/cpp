#include "Harl.hpp"

int main()
{
	Harl harl;
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("DEBUG");
	harl.complain("ERROR");
    harl.complain("random");
    return 0;
}
