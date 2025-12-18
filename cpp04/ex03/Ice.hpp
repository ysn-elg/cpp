#ifndef   ICE_HPP
# define  ICE_HPP

class Ice : public AMateria
{
public:
    Ice();
    Ice(const Ice &other);
    ~Ice();

    Ice &operator(const Ice &other);

    AMateria* clone() const;
    void use(ICharacter& target);
}

#endif
