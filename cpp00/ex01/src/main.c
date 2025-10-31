//#include "PhoneBook.hpp"
#include <iostream>

std::string trim(const std::string& str, const std::string& set)
{
    size_t start = str.find_first_not_of(set);
    if (start == std::string::npos)
        return "";

    size_t end = str.find_last_not_of(set);
    return str.substr(start, end - start + 1);
}


int main()
{
    std::string command;

    while(true)
    {
        std::cout << "Enter a command: ";
        if (!std::getline(std::cin, command))
            break;
        command = trim(command, " \t\v\f\r");
        if (command == "ADD")
            std::cout << "you have selected 'ADD'\n";
        else if (command == "SEARCH")
            std::cout << "you have selected 'SEARCH'\n";
        else if (command == "EXIT")
            break;
        else if (command.empty())
            continue;
        else
            std::cout << command << ": invalid command! try 'ADD', 'SEARCH' or 'EXIT'.\n";
    }
    return 0;
}


