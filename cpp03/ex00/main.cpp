#include "ClapTrap.hpp"

int main() {
    ClapTrap yassine("Yassine");
    ClapTrap othman("Othman");

    yassine.attack("Othman");
    othman.takeDamage(3);

    othman.attack("Yassine");
    yassine.takeDamage(5);

    yassine.beRepaired(4);
    othman.beRepaired(2);

    yassine.attack("Othman");
    othman.takeDamage(6);

    return 0;
}

