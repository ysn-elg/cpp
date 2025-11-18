#ifndef   WEAPON_HPP
#define   WEAPON_HPP 

# include <string>
# include "Weapon.hpp"

class Weapon {

    private:
        std::string _type;

    public:
        Weapon(const std::string& t);
        ~Weapon( void );

        std::string getType( void ) const;
        void        setType(const std::string &t);
};

#endif
