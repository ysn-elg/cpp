#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av)
{
    Harl harl;

    if (ac != 2)
    {
        std::cerr << av[0] << " <levelName>\n"
                  << "Levels: (1) DEBUG, (2) INFO, (3) WARNING, (4) ERROR" << std::endl;
        return 1;
    }
    std::string level = av[1];
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    int start = 0;
    while (start < 4 && levels[start] != level)
        start++;

    if (start == 4)
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            return 1;
    }
    for (int i = start; i < 4; i++)
        harl.complain(levels[i]);
    return 0;
}

