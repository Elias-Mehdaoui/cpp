#ifndef HUMANA_HPP_
#define HUMANA_HPP_
#include "Weapon.hpp"

class HumanA {
    private:
        std::string _name;
        Weapon *_weapon;
    
    public :
        HumanA(std::string name, Weapon& weapon);
        ~HumanA();

        void attack();
};

#endif