#include "AMateria.hpp"

AMateria::AMateria() : type("") { }

AMateria::AMateria(std::string const & type) : type(type) { }

AMateria::AMateria(const AMateria& other) {
    *this = other;
    return *this;
}

AMateria &AMateria::operator=(const AMateria& other) {
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

AMateria::~AMateria() { }

std::string const & AMateria::getType() const { return type; }

void AMateria::use(ICharacter& target) { }
