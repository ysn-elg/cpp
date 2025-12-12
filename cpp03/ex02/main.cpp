#include "FragTrap.hpp"

int main() {
    FragTrap a("Yassine");

    a.attack("Enemy");
    a.takeDamage(20);
    a.beRepaired(10);

    a.highFivesGuys();

    return 0;
}
