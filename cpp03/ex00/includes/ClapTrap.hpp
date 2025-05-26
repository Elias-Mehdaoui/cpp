#include <iostream>
#include <string>

class ClapTrap 
{
    private :
        std::string _name;
        int _hp;
        int _ep;
        int _ad; 

    public :
        ClapTrap(std::string name);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string getName()
        {
            return (_name);
        }
};