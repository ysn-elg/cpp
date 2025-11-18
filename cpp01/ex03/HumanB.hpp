#ifndef  HUMAN_B_HPP
# define HUMAN_B_HPP

# include <string>
#include <iostream>
# include "Weapon.hpp"

class	HumanB
{
	private:
		std::string const	_name;
		Weapon const 		*_weapon;
		
	public:
		HumanB( std::string const& name);
		~HumanB( void );

        void setWeapon(Weapon &newWeapon);
		void	attack( void ) const;
};

#endif
