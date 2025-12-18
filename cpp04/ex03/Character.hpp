#ifndef   CHARACHTER_HPP
# define  CHARACHTER_HPP

class Character : public ICharacter
{
private:
    std::string _name;
    AMateria *inventory[4]; // pointer to inventory?? bcz 'The inventory is empty upon construction.'
public:
    Character();
    Character(const std::string &name);
    Character(const Character &other);
    ~Character();

    Character &operator=(const Character &other);
    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif
