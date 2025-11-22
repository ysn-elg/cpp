#include "PhoneBook.hpp"

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
    PhoneBook   pb;
    std::string command;

    std::cout << "Available commands 'ADD', 'SEARCH' and 'EXIT'." << std::endl; 
    while(true)
    {
        std::cout << "Enter a command: ";
        if (!std::getline(std::cin, command)) 
            return 1;
        command = trim(command, " \t\v\f\r");
        if (command == "ADD")
            pb.addContact();
        else if (command == "SEARCH")
            pb.searchContacts();
        else if (command == "EXIT")
            break;
        else if (command.empty())
            continue;
        else
            std::cout << command << ": invalid command! try 'ADD', 'SEARCH' or 'EXIT'." << std::endl;
    }
    return 0;
}


