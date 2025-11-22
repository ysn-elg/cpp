#ifndef  HUMAN_A_HPP
# define HUMAN_A_HPP

# include <string>
# include "Weapon.hpp"
# include <iostream>

class	HumanA
{
	private:
		std::string const	name;
		Weapon const 		&weapon;
		
	public:
		HumanA( std::string const n, Weapon const &w );

		void	attack( void ) const; 
};

#endif
