#ifndef  HUMAN_B_HPP
# define HUMAN_B_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class	HumanB
{
	private:
		std::string const	name;
		Weapon const 		*weapon;
		
	public:
		HumanB( std::string const& n);

        void setWeapon(Weapon &newWeapon);
		void	attack( void ) const;
};

#endif
