#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Unknown")
{
    std::cout << "WrongAnimal::Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
    std::cout << "WrongAnimal::Constructor called " << _type << " created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    *this = other;
    std::cout << "WrongAnimal::Copy constrcutor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal::Destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
        _type = other._type;
    return (*this);
}

void WrongAnimal::makeSound() const {
    std::cout << "* Generic Wrong animal noise *" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (_type);
}