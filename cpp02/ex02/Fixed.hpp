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
        
        /**/
        bool  operator==(const Fixed &other) const;
        bool  operator>=(const Fixed &other) const;
        bool  operator<=(const Fixed &other) const;
        bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;

        /**/
        Fixed operator*(const Fixed &other) const;
        Fixed operator+(const Fixed &other) const;
        Fixed operator-(const Fixed &other) const;
        Fixed operator/(const Fixed &other) const;

        /**/
        Fixed &operator++();
        Fixed &operator--();
        Fixed operator++(int);
        Fixed operator--(int);
    
        /**/
        static Fixed &min(Fixed &first, Fixed &second);
        static Fixed &max(Fixed &first, Fixed &second);
        static const Fixed &min(const Fixed &first, const Fixed &second);
        static const Fixed &max(const Fixed &first, const Fixed &second);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
