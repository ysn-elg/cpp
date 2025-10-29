#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

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
