#include <iostream>
#include <string>

class Fixed
{
    private:
        int _fp_num;
        static const int _frac_bits = 8;
        
    public :
        Fixed();
        Fixed(const Fixed& copy);
        ~Fixed();

        Fixed& operator=(const Fixed& other);
        
        int getRawBits()
        {
            std::cout << "getRawBits member function called" << std::endl;
            return (_fp_num);
        }

        void setRawBits(int const raw)
        {
            _fp_num = raw;
        }
};