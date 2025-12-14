#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Default constructor called! (Animal)\n";
}

Animal::Animal(const std::string &t) : type(t) {
    std::cout << "Parametrezed constructor called! (Animal)\n";
}

Animal::Animal(const Animal& other) {
    std::cout << "Copy constructor called! (Animal)\n";
    *this = other;
}

Animal &Animal::operator=(const Animal &other) {
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Destructor called! (Animal)\n";
}

std::string Animal::getType() const {
    return type;
}

void Animal::makeSound() const {
    std::cout << "Animal makeSound called!\n";
}
