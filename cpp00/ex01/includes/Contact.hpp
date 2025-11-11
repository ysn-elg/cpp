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
        std::string darkestSecret;
    public:
        void    setFirstName(const std::string&);
        void    setLastName(const std::string&);
        void    setNickName(const std::string&);
        void    setPhoneNumber(const std::string&);
        void    setDarkestSecret(const std::string&);
        
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickName() const;
        std::string getPhoneNumber() const;
        std::string getDarkestSecret() const;
};

#endif
