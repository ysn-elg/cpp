
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    Animal* dog = new Dog();
    // Animal* cat = new Cat();

    dog->makeSound();
    // cat->makeSound();

    delete dog;
    // delete cat;

    // std::cout << "\nDeep copy test:\n";
    // Dog a;
    // Dog b(a);
    // Dog c;
    // c = a;
    //
    return 0;
}
