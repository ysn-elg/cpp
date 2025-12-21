
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    Dog d1;
    Dog d2(d1);
    
    d2.makeSound();

    return 0;
}
