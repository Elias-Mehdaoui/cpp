#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap() 
{
    _name = "anonymous";
    std::cout << "Default Claptrap Constructor called an anonymous was created" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _ad(0) 
{
    std::cout << "ClapTrap::Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
    std::cout << "ClapTrap::Copy constrcutor called" << std::endl;
}


ClapTrap::~ClapTrap() 
{
    std::cout << "ClapTrap::Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        _hp = other._hp;
        _ep = other._ep;
        _ad = other._ad;
    }
    return (*this);
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
    std::cout << _name << " takes " << amount << " damage" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    _hp += amount;
    std::cout << _name << " reparis itself for " << amount << " HP" << std::endl;

}