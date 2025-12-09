#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "FragTrap created with default attributes!\n" ;
    _HP = 100;
    _EP = 100;
    _AD = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    std::cout << "FragTrap named " << name << " created!\n" ;
    _HP = 100;
    _EP = 100;
    _AD = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << "FragTrap copied from another instance!\n";    
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    std::cout << "ScavTrap assigned from another instance!\n"; 
    if (this != &other){
        _name = other._name;
        _HP = other._HP;
        _EP = other._EP;
        _AD = other._AD;
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap "<< _name << " destroyed!\n";
}

void FragTrap::highFivesGuys(void) {
    std::cout << "highFivesGuys\n";
}
