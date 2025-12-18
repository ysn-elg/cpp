#include "Character.hpp"

Character::Character() : _name("") {
    for(int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(const std::string &name) : _name(name) {
    for(int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(const Character& other) {
    *this = other;
}

Character &Character::operator=(const Character &other) { // check it again looks wrong
    if (this != &other) {
        _name = other._name;
        for(int i = 0; i < 4; i++)
            inventory[i] = *(other.inventory)[i];
    }
    return *this;
}

Character::~Character() { }

std::string const & Character::getName() const {
    return _name;
}

void Character::equip(AMateria* m) {
    if (!m)
        return ;
    for(int i = 0; i < 4; i++) {
        if (inventory[i] == NULL) {
            inventory[i] = m;
            break ;
        }
    }
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4)
        return ;
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4)
        return ;
    if (inventory[idx] == NULL)
        return ;
    inventory[idx]->use(target);
}
