#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Default constructor called! (Dog)\n";
    brain = new Brain();
}

Dog::Dog(const std::string &t) : Animal(t) {
    std::cout << "Parameterized constructor called! (Dog)\n";
    brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << "Copy constructor called! (Dog)\n";
    brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << "Copy assignment operator called! (Dog)\n";
    if (this != &other) {
        Animal::operator=(other);
        *brain = *other.brain;
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Destructor called! (Dog)\n";
    delete brain;
}

void Dog::makeSound() const {
    std::cout << "Woof..\n";
}
