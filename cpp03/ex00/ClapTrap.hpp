#ifndef   ClapTrap
# define  ClapTrap

# inlcude <string>

class ClapTrap {
    private:
        std::string _name;
        int         _hitPoint;
        int         _energy_point;
        int         _attack_dammage;
    
    public:
        ClapTrap();
        ClapTrap(const std::string &name);
        ClapTrap(const ClapTrap &other);
        ClapTrap &operator=(const ClapTrap &copy);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
}

#endif
