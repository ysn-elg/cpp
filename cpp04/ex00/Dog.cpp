#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Default constructor called! (Dog)\n";
}

Dog::Dog(const std::string &t) : Animal(t) {
    std::cout << "Parametrezed constructor called! (Dog)\n";
}

Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << "Copy constructor called! (Dog)\n";
    *this = other;
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << "Copy assignement called! (Dog)\n";
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Destructor called! (Dog)\n";
}

void Dog::makeSound() const {
    std::cout << "Woof..\n";
}
