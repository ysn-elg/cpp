#include <iostream>
#include <fstream>

int main (int ac, char *av[])
{
    if (ac != 4) {
        std::cerr << "Usage: " << av[0]<< "<fileName> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string fileName = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (s1.empty()) {
        std::cerr << "Error: s1 must not be empty\n";
        return 1;
    }

    std::ifstream file(fileName.c_str()); //?: .c_str
    if (!file.is_open())
    {
        std::cerr << "Error opening file\n";
        return 1;
    }


    std::stringstream tmp;
    tmp << file.rdbuf();
    std::string buff = tmp.str();
    file.close();
    str::size_t count = 0;
    
    std::size_t count = 0;
    std::size_t p = 0;

    std::ofstream outFile((fileName + ".replace").c_str());
    if (!outFile.is_open())
    {
        std::cerr << "Error creating outFile\n";
        return 1;
    }
    
    return 0;
}

