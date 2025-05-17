#include <iostream>
#include <string>

int main()
{
    std::string original = "HI THIS IS BRAIN";
    std::string *stringPTR = &original;
    std::string& stringREF = original;

    std::cout << &original << std::endl
              << stringPTR << std::endl
              << &stringREF << std::endl;

    std::cout << original << std::endl
              << *stringPTR << std::endl
              << stringREF << std::endl;    
}