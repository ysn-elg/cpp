#include "DiamondTrap.hpp"

int main() {
    DiamondTrap A("Yassine");

    A.attack("enemy");
    A.takeDamage(10);
    A.beRepaired(5);

    A.guardGate();

    A.highFivesGuys();

    A.whoAmI();
    
    return 0;
}

