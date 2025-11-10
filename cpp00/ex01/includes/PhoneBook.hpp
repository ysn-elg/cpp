#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string> // for isdigit!?
#include "Contact.hpp"
#include <iomanip> // for setw

std::string trim(const std::string&, const std::string&); // create new header file for utils ?

class PhoneBook 
{
    private:
        Contact contacts[8];
        int     storedCount;

    public:
        PhoneBook();
        void    addContact();
        void    searchContacts();
};

#endif
