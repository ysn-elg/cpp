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

std::string const & getType() const { return type; }

virtual void use(ICharacter& target)
{
    std::cout << "...";    
}
