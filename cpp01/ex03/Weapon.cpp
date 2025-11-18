#include "Weapon.hpp"

Weapon::Weapon ( const std::string& t) : _type(t) {}

Weapon::~Weapon ( void ) {}

std::string Weapon::getType( void ) const { return _type; }

void        Weapon::setType(const std::string &t) { _type = t; }
