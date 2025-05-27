#include "Character.hpp"

Character::Character() : _name("Unknown"), _slots(new AMateria*[4]()), _floor(new AMateria*[10]()),  _floor_idx(0),  _floor_size(10)
{
    std::cout << "Character::Constructor called" << std::endl;
}

Character::Character(std::string name) : _name(name), _slots(new AMateria*[4]()), _floor(new AMateria*[10]()),  _floor_idx(0),  _floor_size(10)
{
    std::cout << "Character::Constructor called" << std::endl;
}

Character::Character(const Character& other) : _name(other._name), _floor_idx(other._floor_idx), _floor_size(other._floor_size)
{
    _slots = new AMateria*[4]();
    for (int i = 0; i < 4; i++)
    {
        if (other._slots[i])
            _slots[i] = other._slots[i]->clone();
    }
    _floor = new AMateria*[_floor_size]();
    for (int i = 0; i < _floor_idx; i++)
        _floor[i] = other._floor[i]->clone();
    std::cout << "Character::Copy Constructor called" << std::endl;
}
Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (_slots[i])
            delete _slots[i];
    }
    delete[] _slots;
    for (int i = 0; i < _floor_idx + 1; i++)
        delete _floor[i];
    delete[] _floor;
    std::cout << "Character::Destructor called" << std::endl;
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        _name = other._name;
        for (int i = 0; i < 4; i++)
        {
            if (_slots[i])
                delete _slots[i];
        }
        delete[] _slots;
        _slots = new AMateria*[4]();
        for (int i = 0; i < 4; i++)
        {
            if (other._slots[i])
                _slots[i] = other._slots[i]->clone();
        }
        for (int i = 0; i < _floor_idx + 1; i++)
            delete _floor[i];
        delete[] _floor;
        _floor_idx = other._floor_idx;
        _floor = new AMateria*[_floor_size]();
        for (int i = 0; i < other._floor_idx; i++)
            _floor[i] = other._floor[i]->clone();
    }
    return (*this);
}

std::string const & Character::getName() const
{
    return (_name);
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!_slots[i])
        {
            _slots[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (_slots[idx])
    {
        if (_floor_idx + 1 == _floor_size)
        {
            _floor = new AMateria*[_floor_size + 10]();
            _floor_size += 10;
        }
        _floor[_floor_idx] = _slots[idx];
        _floor_idx++;
        _slots[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (_slots[idx])
        _slots[idx]->use(target);
}
