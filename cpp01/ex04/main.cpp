#include <iostream>
#include <fstream>
#include <sstream>

int main (int ac, char *av[])
{
    if (ac != 4) {
        std::cerr << "Usage: " << av[0]<< "<fileName> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string fileName = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
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

    std::string result;
    size_t pos = 0;
    size_t found;

    while ((found = buff.find(s1, pos)) != std::string::npos) {
        result.append(buff, pos, found - pos);
        result.append(s2);
        pos = found + s1.size();
    }
    result += buff.substr(pos);
    
    std::ofstream outFile((fileName + ".replace").c_str());
    if (!outFile.is_open())
    {
        std::cerr << "Error creating outFile\n";
        return 1;
    }
    outFile << result;
    outFile.close();
    return 0;
}

