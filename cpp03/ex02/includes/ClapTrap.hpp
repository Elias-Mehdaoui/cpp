#ifndef CLAPTRAP_HPP_
#define CLAPTRAP_HPP_

#include <iostream>
#include <string>

class ClapTrap 
{
    protected :
        std::string _name;
        int _hp;
        int _ep;
        int _ad; 
    
    public :
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& other);
        ~ClapTrap();

        ClapTrap& operator=(const ClapTrap& other);
        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string getName()
        {
            return (_name);
        }
};

#endif