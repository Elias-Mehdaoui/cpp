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
        
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);