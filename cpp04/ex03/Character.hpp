#ifndef   CHARACHTER_HPP
# define  CHARACHTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <string>

class Character : public ICharacter
{
private:
    std::string _name;
    AMateria *inventory[4];
public:
    Character();
    Character(const std::string &name);
    Character(const Character &other);
    ~Character(); // virtual !!

    Character &operator=(const Character &other);

    std::string const & getName() const;

    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif
