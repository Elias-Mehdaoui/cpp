#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

void ScalarConverter::convert(std::string input)
{
	if (input == "-inf" || input == "-inff")
	{
		std::cout << "char: impossible" <<std::endl;
		std::cout << "int: impossible" <<std::endl;
		std::cout << "float: -inff" <<std::endl;
		std::cout << "double: -inf" <<std::endl;
		return ;
	}
	else if (input == "+inf" || input == "+inff") 
	{
		std::cout << "char: impossible" <<std::endl;
		std::cout << "int: impossible" <<std::endl;
		std::cout << "float: +inff" <<std::endl;
		std::cout << "double: +inf" <<std::endl;
		return ;

	}
	else if (input == "nan" || input == "nanf")
	{
		std::cout << "char: impossible" <<std::endl;
		std::cout << "int: impossible" <<std::endl;
		std::cout << "float: nanf" <<std::endl;
		std::cout << "double: nan" <<std::endl;
		return ;

	}
	double d;
	char *pEnd;

	
	d = strtod(input.c_str(), &pEnd);
	 if (errno == ERANGE){
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }

	if (*pEnd == '\0' || *pEnd == 'f')
	{
		if (d > CHAR_MAX || d < CHAR_MIN)
			std::cout << "char: impossible" << std::endl;
		else if (d < 32 || d == 127)
            std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << static_cast<char>(d) << std::endl;

		if (d < INT_MIN || d > INT_MAX)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(d) << std::endl;

		if (d > FLT_MAX || d < -FLT_MAX)
			std::cout << "float: impossible" << std::endl;
		else	
			std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << std::setprecision(1) << "f" << std::endl;

		std::cout << "double: " << std::fixed << std::setprecision(1) << d <<  std::endl;
	}
	else
	{
		std::cout << "char: impossible" <<std::endl;
		std::cout << "int: impossible" <<std::endl;
		std::cout << "float: impossible" <<std::endl;
		std::cout << "double: impossible" <<std::endl;
	}
}