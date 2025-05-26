#include "../includes/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    _hp = 100;
    _ep = 100;
    _ad = 30;
    std::cout << "FragTrap::Default constructor called";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _hp = 100;
    _ep = 100;
    _ad = 30;
    std::cout << "FragTrap::Constrcutor called " << _name << " joined the fight" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap::copy Constrcutor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap::Destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
    {
        _hp = other._hp;
        _ep = other._ep;
        _ad = other._ad;
    }
    return (*this);
}


void FragTrap::attack(const std::string& target)
{
    if (_ep < 1)
        std::cout << "Not enough energy to do that" << std::endl;
    else if (_hp < 1)
        std::cout << "Dead cant attack" << std::endl;
    else
        std::cout << "FragTrap::" << _name << " deals " << target << " " << _ad << " points of damage" << std::endl; 
}

void FragTrap::highFivesGuys()
{
    std::cout << _name << " wants a high five" << std::endl;
}
