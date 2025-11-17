#ifndef   WEAPON_HPP
#define   WEAPON_HPP 

# include <string>

class Weapon {

    private:
        std::string _type;

    public:
        Weapon( void );
        Weapon(const std::string& t);
        ~Weapon( void );

        std::string getType( void ) const;
        void        setType(const std::string &t);
};

#endif
