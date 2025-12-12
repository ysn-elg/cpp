#ifndef   CLAPTRAP_HPP
# define  CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap {
    protected:
        std::string _name;
        int         _HP;
        int         _EP;
        int         _AD;

    public:
        ClapTrap();
        ClapTrap(const std::string &name);
        ClapTrap(const ClapTrap &other);
        ClapTrap &operator=(const ClapTrap &copy);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif
