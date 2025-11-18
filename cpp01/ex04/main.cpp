#include <iostream>

int int main (int ac, char *av[])
{
    if (ac != 4) {
        std::cerr << "usage: " << av[0]<< "<fileName> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (s1.empty()) {
        std::cerr << "Error: s1 must not be empty\n";
        return 1;
    }
}

