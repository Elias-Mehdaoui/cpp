#include "../includes/HumanB.hpp"
#include <cstddef>

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
    return ;
}
HumanB::~HumanB() 
{
    return ;
}

void HumanB::attack()
{
    std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}