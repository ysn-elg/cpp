#ifndef   WRONG_CAT_HPP
# define  WRONG_CAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
    WrongCat();
    WrongCat(const std::string &t);
    WrongCat(const WrongCat& other);
    ~WrongCat();
    WrongCat &operator=(const WrongCat& other);

    void makeSound() const;
};

#endif
