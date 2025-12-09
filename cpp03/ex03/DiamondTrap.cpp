#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Yassine" + "_clap_name") {
    _HP = FragTrap::_HP;
    _EP = ScavTrap::_EP;
    _AD = FragTrap::_AD;

    std::string << "DiamondTrap " << _name << " created\n";
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name") {
    _HP = FragTrap::_HP;
    _EP = ScavTrap::_EP;
    _AD = FragTrap::_AD;

    std::string << "DiamondTrap (param) " << _name << " created\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) {

}
