#include "Zombie.hpp"

Zombie::Zombie ( void ) : name("") { }

Zombie::Zombie (const std::string& n) : name(n) {
    std::cout << "A new Zombie called '" << name << "' is just born." << std::endl;
}

Zombie::~Zombie ( void ) { }

void Zombie::announce( void ) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// void  Zombie::setName(std::string name) {
//     Zombie z(name);
// }
