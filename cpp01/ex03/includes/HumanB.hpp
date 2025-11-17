#ifndef  HUMAN_B_HPP
# define HUMAN_B_HPP

# include <string>
# include "Weapon.hpp"

class	HumanB
{
	private:
		std::string const	_name;
		Weapon const 		&_weapon;
		
	public:
		HumanA( std::string const name, Weapon const &weapon );
		~HumanA( void );

		void	attack( void ) const; // without angle bracket ?
};

#endif
