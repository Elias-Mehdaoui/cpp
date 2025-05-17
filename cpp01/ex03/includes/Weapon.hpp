#ifndef WEAPON_HPP_
#define WEAPON_HPP_
#include <string>
#include <iostream>

class Weapon {
    private:
        std::string _type;
    
    public:
        Weapon(std::string type);
        ~Weapon();

        const std::string& getType()
        {
            const std::string& _typeRef = _type;
            return (_typeRef);
        }

        void setType(std::string type)
        {
            _type = type;
        }
};


#endif