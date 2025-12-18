#include "Ice.hpp"

Ice::Ice() : AMateria("ice") { }

Ice::Ice(const Ice &other) : AMateria(other) { }

Ice::~Ice() { }

Ice &Ice::operator=(const Ice &other) {
    if (this != other) {
        Ice::operator=other;
    }
    return *this;
}

AMateria* Ice::clone() const {
    return (new *this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
