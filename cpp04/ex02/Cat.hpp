#ifndef   CAT_HPP
# define  CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
private:
    Brain *brain;
public:
    Cat();
    Cat(const std::string &t);
    Cat(const Cat& other);
    ~Cat();
    Cat &operator=(const Cat& other);

    void makeSound() const;
};

#endif
