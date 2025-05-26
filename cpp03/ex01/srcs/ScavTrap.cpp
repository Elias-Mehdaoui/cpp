#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    _hp = 100;
    _ep = 50;
    _ad = 20;
    std::cout << "Default ScavTrap constructor called";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _hp = 100;
    _ep = 50;
    _ad = 20;
    std::cout << "ScavTrap::Constrcutor called " << _name << " joined the fight" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "copy Constrcutor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap::Destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        _hp = other._hp;
        _ep = other._ep;
        _ad = other._ad;
    }
    return (*this);
}


void ScavTrap::attack(const std::string& target)
{
    if (_ep < 1)
        std::cout << "Not enough energy to do that" << std::endl;
    else if (_hp < 1)
        std::cout << "Dead cant attack" << std::endl;
    else
        std::cout << _name << " is a ScavTrap and deals " << target << " " << _ad << " points of damage" << std::endl; 
}

void ScavTrap::guardGate()
{
    std::cout << _name << " is now in gate keep mode " << std::endl;
}
