#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkSecret;
    public:
        void    getFirstName(std::string);
        void    getLastName(std::string);
        void    getNickName(std::string);
        void    getPhoneNumber(std::string);
        void    getDarkSecret(std::string);
        
        std::string getFirstName();
        std::string getLastName();
        std::string getNickName();
        std::string getPhoneNumber();
        std::string getDarkSecret();
}

#endif
