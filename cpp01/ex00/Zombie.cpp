#include "Zombie.hpp"

Zombie::Zombie (const std::string& n) : name(n) {
    std::cout << "A new Zombie called '" << name << "' is just born." << std::endl;
} // print somthing !?

Zombie::~Zombie ( void ) {
    std::cout << "Zombie " << name << " is died." << std::endl;
}

void Zombie::announce( void ) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
