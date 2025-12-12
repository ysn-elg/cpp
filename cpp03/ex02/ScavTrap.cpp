#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap default constructor called!\n";
    _HP = 100;
    _EP = 50;
    _AD = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    std::cout << "ScavTrap parameterized constructor called!"
              << " (name: " << _name << " )\n";
    _HP = 100;
    _EP = 50;
    _AD = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap copie contructor called!\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap copie assignement operator called!\n";
    if (this != &other) {
        _name = other._name;
        _HP = other._HP;
        _EP = other._EP;
        _AD = other._AD;
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called!\n";
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap has entered Gate Keeper mode!\n";
}

