#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime> 

Base* generate();
void identify(Base* p);
void identify(Base& p);

Base* Generate()
{
    int random = (rand() % 3);

    std::cout << "rand = " << random << std::endl; 

    if (random == 0)
        return (new A());
    else if (random == 1)
        return (new B());
    else
        return (new C());
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{

    try {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } 
    catch (...) {
        try {
            dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        } 
        catch (...) {
            std::cout << "C" << std::endl;
        }
    }
}

int main()
{
    std::srand(std::time(0));
    Base* test = Generate();
    identify(test);
    identify(*test);
}
