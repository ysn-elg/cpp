#ifndef   WRONG_ANIMAL_HPP
# define  WRONG_ANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal {
protected:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal(const std::string &t);
    WrongAnimal(const WrongAnimal &other);
    WrongAnimal &operator=(const WrongAnimal &other);
    virtual ~WrongAnimal();

    std::string getType() const;
    void makeSound() const;
};

#endif
