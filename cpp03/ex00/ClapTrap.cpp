#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Yassine"), _HP(10), _EP(10), _AD(0) {
    std::cout << "ClapTrap default constructor called!\n";
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _HP(10), _EP(10), _AD(0) {
    std::cout << "ClapTrap parameterized constructor called!"
              << " (name: " << _name << " )\n";
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    std::cout << "ClapTrap copie contructor called!\n";
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap copie assignement operator called!\n";
    if (this != &other)
    {
        _name = other._name;
        _HP = other._HP;
        _EP = other._EP;
        _AD = other._AD;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called!\n";
}

void ClapTrap::attack(const std::string& target) {
    if (_EP <= 0) {
        std::cout << "ClapTrap " << _name << " has no energy left to attack!\n";
        return ;
    }
    if (_HP <= 0) {
        std::cout << "ClapTrap " << _name << " is destroyed and cannot attack!\n";
        return ;
    }
    _EP--;
    std::cout << "ClapTrap " << _name << " attacks " << target
              << ", causing "  << _AD << " of damage! (EP now: " << _EP << ")\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_HP <= 0) {
        std::cout << "ClapTrap " << _name << " is already destroyed!\n";
        return ;
    }

    _HP -= amount;
    if (_HP < 0)
        _HP = 0;
    std::cout << "ClapTrap " << _name << " takes " << amount
              << " damage! (HP now: " << _HP << ")\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_EP <= 0) {
        std::cout << "ClapTrap " << _name << " has no energy left to repair!\n";
        return;
    }
    if (_HP <= 0) {
        std::cout << "ClapTrap " << _name << " is destroyed and cannot be repaired!\n";
        return;
    }

    _EP--;
    _HP += amount;

    std::cout << "ClapTrap " << _name << " repairs itself for " << amount
              << " HP! (HP now: " << _HP << ", EP now: " << _EP << ")\n";
}
