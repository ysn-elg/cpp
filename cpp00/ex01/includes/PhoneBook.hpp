#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string> 
#include "Contact.hpp"
#include <iomanip>
#include <cstdlib>

std::string trim(const std::string&, const std::string&);

class PhoneBook 
{
    private:
        Contact contacts[8];
        int     storedCount;
        int     lastContact;
    public:
        PhoneBook() : storedCount(0), lastContact(-1) {}
        void    addContact();
        void    searchContacts();
};

#endif
