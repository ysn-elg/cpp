#include "PhoneBook.hpp"
#include <functional> // for declare function as a prameter
#include <cstdlib> // for exit function

PhoneBook::PhoneBook() : storedCount(-1) { }

int setData(const std::string& msg, void (Contact::*func)(const std::string&), Contact& obj)
{
    std::string tmp;

    while(true)
    {
        std::cout << msg;
        if (!std::getline(std::cin, tmp))
            exit(1);
        tmp = trim(tmp, " \t\v\f\r");
        if (!tmp.empty())
            break ;
    }
    (obj.*func)(tmp);
    return 0;
}

void    PhoneBook::addContact()
{
    std::string tmp;
    
    storedCount = (storedCount + 1) % 8;
    setData("   First name: ", &Contact::setFirstName, contacts[storedCount]); // check typing
    setData("   Last name: ", &Contact::setLastName, contacts[storedCount]);
    setData("   Nick name: ", &Contact::setNickName, contacts[storedCount]); // the [&] !!?
    setData("   Phone number: ", &Contact::setPhoneNumber, contacts[storedCount]);
    setData("   Darkest secret: ", &Contact::setDarkestSecret, contacts[storedCount]);
}

// |-------------------------------------------|
// |     Index|First name| Last name|  Nickname|
// |-------------------------------------------|
// |         0|   Yassine|El guaddar| Wayassine|
// |-------------------------------------------|
// |         1|AAAAAAAAA.|sssssssss.|ddddddddd.|
// |-------------------------------------------|

std::string    formatField(const std::string& str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    else
        return str;
}

void    displayContact(Contact C, int index)
{
    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|" << std::setw(10) << index; 
    std::cout << "|" << std::setw(10) << formatField(C.getFirstName());
    std::cout << "|" << std::setw(10) << formatField(C.getLastName());
    std::cout << "|" << std::setw(10) << formatField(C.getNickName());
    std::cout << "|" << std::endl;
    // std::cout << "----------------------------------------------" << endl;
}

int    chooseIndex()
{
    std::string index;

    while(true)
    {
        std::cout << "Select index for more informations: ";
        if (!std::getline(std::cin, index))
            exit(1);
        index = trim(index, " \t\v\f\r");
        if (!index.empty() && std::isdigit(index[0]) && index.length() == 1)
            return (index[0] - '0');
    }
    return -1;
}

void    printContact(Contact C)
{   
   std::cout << "First name: " << C.getFirstName() << std::endl;
   std::cout << "Last name: " << C.getLastName() << std::endl;
   std::cout << "Nick name: " << C.getNickName() << std::endl ;
   std::cout << "Phone number: " << C.getPhoneNumber() << std::endl;
   std::cout << "Darkest secret: " << C.getDarkestSecret() << std::endl;
}

void    PhoneBook::searchContacts()
{
    if (storedCount < 0)
    {
        std::cout << "PhoneBook is empty" << std::endl;
        return ; //todo: 
    }
    for (int i = 0; i <= storedCount; i++)
        displayContact(contacts[i], i);
    int index = chooseIndex();
    while (index > storedCount)
    {
        std::cout << "invalid index !!" << std::endl;
        index = chooseIndex();
    }
    printContact(contacts[chooseIndex()]);
}

