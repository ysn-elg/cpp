#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), _name("Default")
{
    std::cout << "DiamondTrap default constructor called!\n";

    _HP = 100;
    _EP = 50;
    _AD = 30;
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), _name(name)
{
    std::cout << "DiamondTrap parameterized constructor called!\n";

    _HP = 100;
    _EP = 50;
    _AD = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other)
{
    std::cout << "DiamondTrap copie contructor called!\n";
    
    _name = other._name;
    _HP = 100;
    _EP = 50;
    _AD = 30;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << "DiamondTrap copie assignement operator called!\n";

    if (this != &other)
    {
        _name = other._name;
        ClapTrap::_name = other.ClapTrap::_name;
        _HP = other._HP;
        _EP = other._EP;
        _AD = other._AD;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called!\n";
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << _name
              << " | ClapTrap name: " << ClapTrap::_name << std::endl;
}
