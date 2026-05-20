#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern {
private:
    AForm* createShrubbery(const std::string& target) const;
    AForm* createRobotomy(const std::string& target) const;
    AForm* createPresidential(const std::string& target) const;
public:
    Intern();
    Intern(const Intern& other);
    ~Intern();

    Intern &operator=(const Intern& other);

    AForm* makeForm(const std::string& formName, const std::string& target) const;
};

#endif
