#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstddef>
#include <iostream>
#include <ostream>

Intern::Intern() { }

Intern::Intern(const Intern& other) { (void)other; }

Intern::~Intern() { }

Intern &Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

AForm* Intern::createShrubbery(const std::string& target) const
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) const
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target) const
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const
{
    std::string forms[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    
    AForm* (Intern::*funcs[])(const std::string &) const = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };

    for(std::size_t i = 0; i < 3; i++) {
        if (formName == forms[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*funcs[i])(target);
        }
    }
    std::cout << "Error: unknown form \"" << formName << "\"" << std::endl;
    return NULL;
}
