#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "FragTrap default constructor called!\n";
    _HP = 100;
    _EP = 100;
    _AD = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    std::cout << "FragTrap parameterized constructor called!"
              << " (name: " << _name << " )\n";
    _HP = 100;
    _EP = 100;
    _AD = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << "FragTrap copie contructor called!\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    std::cout << "FragTrap copie assignement operator called!\n"; 
    if (this != &other){
        _name = other._name;
        _HP = other._HP;
        _EP = other._EP;
        _AD = other._AD;
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called!\n";
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name << " requests a high five!" << std::endl;
}
