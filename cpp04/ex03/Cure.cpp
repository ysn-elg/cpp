#include "Cure.hpp"

Cure::Cure() : AMateria("ice") { }

Cure::Cure(const Cure &other) : AMateria(other) { }

Cure::~Cure() { }

Cure &Cure::operator=(const Cure &other) {
    if (this != other) {
        Cure::operator=other;
    }
    return *this;
}

AMateria* Cure::clone() const {
    return (new *this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "’s wounds *\n";
}
