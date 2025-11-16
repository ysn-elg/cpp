#include "Zombie.hpp"

int main () {
    // heap Zombie
    Zombie *z = newZombie("Ansamble");
    z->announce();
    delete z;

    // stack ??
    randomChump("ALLO!?");
    return 0;
}
