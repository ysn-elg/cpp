#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "Default constructor called! (WrongAnimal)\n";
}

WrongAnimal::WrongAnimal(const std::string &t) : type(t) {
    std::cout << "Parameterized constructor called! (WrongAnimal)\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    std::cout << "Copy constructor called! (WrongAnimal)\n";
    *this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    std::cout << "Copy assignment operator called! (WrongAnimal)\n";
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Destructor called! (WrongAnimal)\n";
}

std::string WrongAnimal::getType() const {
    return type;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal makeSound called!\n";
}
