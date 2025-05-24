#include <iostream>
#include "includes/Fixed.hpp"

int main ()
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed c(3);
	Fixed d(5);

	std::cout << "a is fixed at " << a << std::endl;
	std::cout << "b is fixed at " << b << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;
	std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
	
	std::cout << "c is fixed at " << c << std::endl;
	std::cout << "d is fixed at " << d << std::endl;

	std::cout << "c + d = " << c + d << std::endl;
	std::cout << "c - d = " << c - d << std::endl;
	std::cout << "c * d = " << c * d << std::endl;
	std::cout << "c / d = " << c / d << std::endl;
	
	std::cout << "c >= d " << ((c >= d) ? true : false ) << std::endl;
	std::cout << "c > d " << ((c > d) ? true : false ) << std::endl;
	std::cout << "c < d " << ((c < d) ? true : false ) << std::endl;
	std::cout << "c <= d " << ((c <= d) ? true : false ) << std::endl;
	std::cout << "c == d " << ((c == d) ? true : false ) << std::endl;
	std::cout << "c != d " << ((c != d) ? true : false ) << std::endl;

	return (0);
}