#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "Default constructor called! (Cat)\n";
}

Cat::Cat(const std::string &t) : Animal(t) {
    std::cout << "Parametrezed constructor called! (Cat)\n";
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Copy constructor called! (Cat)\n";
    *this = other;
}

Cat &Cat::operator=(const Cat& other) {
    std::cout << "Copy assignement operator called! (Cat)\n";
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Destructor called! (Cat)\n";
}

void Cat::makeSound() const {
    std::cout << "Meow..\n";
}
