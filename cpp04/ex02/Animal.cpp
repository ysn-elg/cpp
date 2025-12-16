#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Default constructor called! (Animal)\n";
}

Animal::Animal(const std::string &t) : type(t) {
    std::cout << "Parameterized constructor called! (Animal)\n";
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Copy constructor called! (Animal)\n";
}

Animal &Animal::operator=(const Animal &other) {
    std::cout << "Copy assignment operator called! (Animal)\n";
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
