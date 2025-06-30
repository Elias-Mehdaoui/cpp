
#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>

int main (int ac, char **av)
{
	if (ac != 2)
		return (std::cout << "Miss arg\n", 1);
	ScalarConverter::convert(av[1]);
}