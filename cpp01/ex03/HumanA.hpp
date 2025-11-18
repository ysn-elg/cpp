#ifndef  HUMAN_A_HPP
# define HUMAN_A_HPP

# include <string>
# include "Weapon.hpp"
# include <iostream>

class	HumanA
{
	private:
		std::string const	_name;
		Weapon const 		&_weapon;
		
	public:
		HumanA( std::string const name, Weapon const &weapon );
		~HumanA( void );

		void	attack( void ) const; 
};

#endif
