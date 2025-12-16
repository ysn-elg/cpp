#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "Default constructor called! (WrongCat)\n";
}

WrongCat::WrongCat(const std::string &t) : WrongAnimal(t) {
    std::cout << "Parameterized constructor called! (WrongCat)\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    std::cout << "Copy constructor called! (WrongCat)\n";
    *this = other;
}

WrongCat &WrongCat::operator=(const WrongCat& other) {
    std::cout << "Copy assignment operator called! (WrongCat)\n";
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "Destructor called! (WrongCat)\n";
}

void WrongCat::makeSound() const {
    std::cout << "Meow..\n";
}
