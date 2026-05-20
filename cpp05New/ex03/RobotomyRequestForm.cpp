#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

RobotomyRequestForm::RobotomyRequestForm()
        : AForm("RobotomyRequestForm", 72, 45), _target("x") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
        : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
        : AForm(other), _target(other._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
        _target = other._target;
    return *this;
}

void RobotomyRequestForm::beExecuted() const {
    std::cout << "Vrrr.. Vrrrr.. (drilling noises)" << std::endl;
    std::srand(std::time(0));
    if (std::rand() % 2)
        std::cout << _target << "has been robotomized successfully" << std::endl;
    else
        std::cout << "Robotomy failed for " << _target << std::endl;
}
