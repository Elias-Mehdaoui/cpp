#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(&weapon)
{
    return ;
}
HumanA::~HumanA() 
{
    return ;
}

void HumanA::attack()
{
    std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}