#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *Z = new Zombie[N];
    for (int i = 0; i < N; i++) {
        Z[i] = Zombie(name);
    }
    return Z;
}
