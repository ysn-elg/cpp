#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "Default constructor called! (Cat)\n";
    brain = new Brain();
}

Cat::Cat(const std::string &t) : Animal(t) {
    std::cout << "Parameterized constructor called! (Cat)\n";
    brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Copy constructor called! (Cat)\n";
    brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat& other) {
    std::cout << "Copy assignment operator called! (Cat)\n";
    if (this != &other) {
        Animal::operator=(other);
        *brain = *other.brain;
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Destructor called! (Cat)\n";
    delete brain;
}

void Cat::makeSound() const {
    std::cout << "Meow..\n";
}
