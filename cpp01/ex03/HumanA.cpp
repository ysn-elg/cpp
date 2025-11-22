#include "HumanA.hpp"

HumanA::HumanA( std::string const n, Weapon const &w) : 
            name(n), weapon(w) {}

void  HumanA::attack( void ) const {
    std::cout << name << " attacks with their "
              << weapon.getType() << std::endl;
}
