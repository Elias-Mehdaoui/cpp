#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    private:
        int _value;
        static const int _frac_bits = 8;
        
    public :
        Fixed();
        Fixed(const Fixed& copy);
        Fixed(int value);
        Fixed(const float value);
        ~Fixed();
        
        float toFloat() const;
        int toInt() const;
        Fixed& operator=(const Fixed& other);

        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        Fixed& operator++();       
        Fixed operator++(int);     
        Fixed& operator--();       
        Fixed operator--(int);

        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
        
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);