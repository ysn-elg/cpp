#include "Zombie.hpp"

int main () {
    Zombie *z = newZombie("Ansamble");
    z->announce();
    delete z;

    randomChump("ALLO!?");
    return 0;
}
