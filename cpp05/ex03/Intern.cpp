#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() { }

Intern::Intern(const Intern& other) { (void)other; }

Intern::~Intern() { }

Intern &Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

AForm* Intern::makeForm(const std::string formName, const std::string target) const
{
    std::string forms[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*funcs[])(const std::string &) = {  &ShrubberyCreationForm::clone,
                                                &RobotomyRequestForm::clone,
                                                &PresidentialPardonForm::clone };
    for (int i = 0; i < 3; i++) {
        if (formName == forms[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return funcs[i](target);
        }
    }
    std::cout << "Intern: unexist form!" << std::endl;
    return NULL;
}
