#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    Animal  a;
    Dog     d;
    Cat     c;

    std::cout << "---------------------------------\n";
    a.makeSound();
    std::cout << "type: " << a.getType() << std::endl;

    std::cout << "---------------------------------\n";
    d.makeSound();
    std::cout << "type: " << d.getType() << std::endl;

    std::cout << "---------------------------------\n";
    c.makeSound();
    std::cout << "type: " << c.getType() << std::endl;

    std::cout << "---------------------------------\n";

    return 0;
}
