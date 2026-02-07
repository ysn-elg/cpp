#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
                : AForm("RobotomyRequestForm", 72, 45), _target("x")
{ }

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
                : AForm("RobotomyRequestForm", 72, 45), _target(target)
{ }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm&other)
                : AForm(other), _target(other._target)
{ }

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm&other)
{
    if (this != &other)
        _target = other._target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{ }

void RobotomyRequestForm::beExecuted() const
{
    std::srand(std::time(0));
    std::cout << "Drilling noises Brrrrr..Vvrrrr..#!$%?*&..." << std::endl;
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "Robotomy failed for " << _target << std::endl;
}

AForm *RobotomyRequestForm::clone(const std::string &target)
{
    return new RobotomyRequestForm(target);
}
