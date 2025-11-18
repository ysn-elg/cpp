#include "HumanB.hpp"

HumanB::HumanB( std::string const& name) : 
            _name(name), _weapon(NULL) {}

HumanB::~HumanB( void ) {}

void  HumanB::setWeapon(Weapon &Weapon) {
    _weapon = &Weapon;
}

void  HumanB::attack( void ) const {
    if (_weapon)
        std::cout << _name << " attacks with " << _weapon->getType() << std::endl;
    else
        std::cout << _name << " has no weapon" << std::endl;
}
