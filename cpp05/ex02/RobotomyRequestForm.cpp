#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib> /* rand() */

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
    std::cout << "...Drilling noises..." << std::endl;
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "Robotomy failed for " << _target << std::endl;
}
