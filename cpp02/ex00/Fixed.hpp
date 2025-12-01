#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
    private:
        int _number;
        static const int _bits;
    public:
        Fixed( void );
        Fixed(const Fixed &copy);
        Fixed &operator=(const Fixed &other);
        ~Fixed( void );

        int   getRawBits( void ) const;
        void  setRawBits(int const raw);
};

#endif
