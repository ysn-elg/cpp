#include "PhoneBook.hpp"

int setData(const std::string& msg, const std::function<void(const std::string&)>& func) // check parameter again
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
    if (setData("   First name: ", contacts[storedCount].setFirstName) \\ check typing
    ||  setData("   Last name: ", contacts[storedCount].setLastName)
    ||  setData("   Nick name: ", contacts[storedCount].setNickName)
    ||  setData("   Phone number: ", contacts[storedCount].setPhoneNumber)
    ||  setData("   Darkest secret: ", contacts[storedCount].setDarkestSecret)) 
            return 1;
    return 0;
}

std::string    formatField(const std::string& str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    else
        return str;
}

void    displayContact(Contact C)
{
    
}

void    PhoneBook::searchContact()
{
    if (storedCount < 0)
    {
        std::cout "PhoneBook is empty" << endl;
        return ; //todo: 
    }
    
}
