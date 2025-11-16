#include "Zombie.hpp"

int main()
{
    int N = 7;
    std::string str = "ALLO";
    Zombie *Z = zombieHorde(N, str);
    for (int i = 0; i < N; i++) {
        Z[i].announce();
    }
    delete []Z;
    return 0;
}
