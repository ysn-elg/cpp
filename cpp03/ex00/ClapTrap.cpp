#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :  _name(""),
                        _hitPoint(10),
                        _energyPoint(10),
                        _attack_dammage(0)
{
    std::cout << "Default constructor called!\n";
}

ClapTrap::ClapTrap(const std::string &name) :   _name(name),
                                                _hitPoint(10),
                                                _energyPoint(10),
                                                _attack_dammage(0)
{
    std::cout << "Parameterized constructor called!\n";
}


