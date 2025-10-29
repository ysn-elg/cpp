//#include "PhoneBook.hpp"
#include <iostream>
int main() {
    std::string command;

    std::cout <<"Available commands: ADD, SEARCH, EXIT.\n";
    while(true)
    {
        std::cout << "Enter a command: ";
        std::getline(std::cin, command);
        if (command == "ADD")
            std::cout << "you have selected 'ADD'\n";
        else if (command == "SEARCH")
            std::cout << "you have selected 'SEARCH'\n";
        else if (command == "EXIT")
            break;
        else if (command.empty())
            continue;
        else
        {
            std::cout << "  Invalid command! try:  ADD, SEARCH or EXIT.\n";
        }
    }
    return 0;
}


