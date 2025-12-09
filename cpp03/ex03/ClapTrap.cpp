#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Yassine"), _HP(10), _EP(10), _AD(0) {
    std::cout << "ClapTrap created with default attributes!\n";
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _HP(10), _EP(10), _AD(0) {
    std::cout << "ClapTrap named " << name << " created!\n";
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    std::cout << "ClapTrap copied from another instance!\n";
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap assigned from another instance!\n";
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
    std::cout << "ClapTrap "<< _name << " destroyed!\n";
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

