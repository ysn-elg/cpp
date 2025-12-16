#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Default constructor called! (Brain)\n";
    for (int i = 0; i < 100; ++i)
        ideas[i] = "";
}

Brain::Brain(const Brain& other) {
    std::cout << "Copy constructor called! (Brain)\n";
    *this = other;
}

Brain::~Brain() {
    std::cout << "Destructor called! (Brain)\n";
}

Brain &Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return *this;
}
