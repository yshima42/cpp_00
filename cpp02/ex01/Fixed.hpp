#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _raw;
        static const int _point = 8;

    public:
        Fixed();
        Fixed(int n);
        Fixed(float n);
        ~Fixed();
        Fixed(Fixed const &other);
        Fixed &operator=(Fixed const &other);

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &ost, Fixed const &fixed);

#endif
