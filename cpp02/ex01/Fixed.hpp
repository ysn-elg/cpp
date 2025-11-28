#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
    private:
        int _number;
        static const int _bits;
    public:
        Fixed( void );
        Fixed(const int number);
        Fixed(const float number);
        Fixed(const Fixed &copy);
        Fixed &operator=(const Fixed &other);
        ~Fixed( void );

        int   getRawBits( void ) const;
        void  setRawBits(int const raw);
        float toFloat( void ) const;
        int   toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
