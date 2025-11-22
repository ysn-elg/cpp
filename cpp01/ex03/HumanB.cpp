#include "HumanB.hpp"

HumanB::HumanB( std::string const& n) : name(n) {
    weapon = NULL;
}

void  HumanB::setWeapon(Weapon &newWeapon) { weapon = &newWeapon; }

void  HumanB::attack( void ) const {
    if (weapon)
        std::cout << name << " attacks with " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon" << std::endl;
}
