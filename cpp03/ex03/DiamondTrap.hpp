#ifndef   DIAMONDTRAP_HPP
# define  DIAMONDTRAP_HPP

# include "FlagTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FlagTrap, public ScavTrap{
private:
    std::string _name;
public:
    DiamondTrap();
    DiamondTrap(const std::srting& name);
    DiamondTrap(const DiamondTrap& other);
    ~DiamondTrap();

    DiamondTrap& operator=(const DiamondTrap& other);
    void whoAmI();
};

#endif
