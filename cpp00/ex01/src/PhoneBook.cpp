#include "PhoneBook.hpp"

int setData(const std::string msg, void (*func)(const std::string))
{
    std::string tmp;

    while(true)
    {
        std::cout << msg;
        if (!std::getline(std::cin, tmp)
            return 1;
        tmp = trim(tmp, " \t\v\f\r");
        if (!tmp.empty())
            break ;
    }
    func(tmp);
    return 0;
}

void    PhoneBook::addContact()
{
    std::string tmp;
    
    storedCount = (storedCount + 1) % 8;
    if (setData("First name: ", contacts[storedCount].setFirstName)
        || setData("Last name: ", contacts[storedCount].setLastName)
        || setData("Nick name: ", contacts[storedCount].setNickName)
        || setData("Phone number: ", contacts[storedCount].setPhoneNumber)
        || setData("Darkest secret: ", contacts[storedCount].setDarkestSecret)) 
            return 1;
    return 0;
}
