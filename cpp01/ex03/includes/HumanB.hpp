#ifndef HUMANB_HPP_
#define HUMANB_HPP_
#include "Weapon.hpp"

class HumanB {
    private:
        std::string _name;
        Weapon *_weapon;
    
    public :
        HumanB(std::string name);
        ~HumanB();

        void attack();

        void setWeapon(Weapon& weapon)
        {
            _weapon = &weapon;
        }
};

#endif