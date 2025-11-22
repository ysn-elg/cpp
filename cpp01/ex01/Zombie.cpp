#include "Zombie.hpp"

Zombie::Zombie ( void ) : name("") { }

Zombie::~Zombie ( void ) {
    std::cout << "Zombie " << name << " is died." << std::endl;
}

void Zombie::announce( void ) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void  Zombie::setName(const std::string& n) { name = n; }
