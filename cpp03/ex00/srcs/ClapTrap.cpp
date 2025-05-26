#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _ad(0) 
{
    std::cout << "Constructor called" << std::endl;
}

ClapTrap::~ClapTrap() 
{
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (_ep < 1)
        std::cout << "Not enough energy to do that" << std::endl;
    else if (_hp < 1)
        std::cout << "Dead cant attack" << std::endl;
    else
        std::cout << _name << " attacks " << target << ", causing " << _ad << " points of damage " << std::endl;   
}

void ClapTrap::takeDamage(unsigned int amount)
{
    _hp -= amount;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    _hp += amount;
}