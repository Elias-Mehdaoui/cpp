#include "RPN.hpp"



int main(int argc, char **argv)
{
    RPN rpn;

    if (argc == 2)
    {
        try 
		{
			std::cout << rpn.calculate(argv[1]) << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
    }
    else
		std::cout << "Error: Wrong args" << std::endl;
}