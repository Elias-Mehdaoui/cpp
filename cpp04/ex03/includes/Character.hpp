#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter 
{
    private :
        std::string _name;
        AMateria **_slots;
        AMateria **_floor;
        int _floor_idx;
        int _floor_size;
    
    public :
        Character();
        Character(std::string name);
        Character(const Character& other);
        ~Character();
        Character& operator=(const Character& other);

        std::string const & getName() const;
        int getFloorSize() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};