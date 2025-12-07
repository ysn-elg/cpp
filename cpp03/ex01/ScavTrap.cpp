#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap created with default attributes!\n";
    _HP = 100;
    _EP = 50;
    _AD = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    std::cout << "ScavTrap named " << name << " created!\n";
    _HP = 100;
    _EP = 50;
    _AD = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    std::cout << "ScavTrap copied from another instance!\n";
    *this = other; ////////////////////
}

ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ClapTrap assigned from another instance!\n";
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
    std::cout << "ClapTrap "<< _name << " destroyed!\n";
}

