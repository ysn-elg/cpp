#include "PhoneBook.hpp"

void    Contact::setFirstName(const std::string& name)      { firstName = name; }

void    Contact::setLastName(const std::string& name)       { lastName = name; }

void    Contact::setNickName(const std::string& name)       { nickName = name; }

void    Contact::setPhoneNumber(const std::string& number)  { phoneNumber = number; }

void    Contact::setDarkestSecret(const std::string& secret)   { darkestSecret = secret; }

std::string Contact::getFirstName() const   { return firstName; }

std::string Contact::getLastName() const    { return lastName; }

std::string Contact::getNickName() const    { return nickName; }

std::string Contact::getPhoneNumber() const { return phoneNumber; }

std::string Contact::getDarkestSecret() const  { return darkestSecret; }

