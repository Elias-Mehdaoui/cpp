#include "../includes/Animal.hpp"

Animal::Animal() : _type("Unknown")
{
    std::cout << "Animal::Constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "Animal::Constructor called " << _type << " created" << std::endl;
}

Animal::Animal(const Animal& other)
{
    *this = other;
    std::cout << "Animal::Copy constrcutor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal::Destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
        _type = other._type;
    return (*this);
}

void Animal::makeSound() const {
    std::cout << "* Generic animal noise *" << std::endl;
}

std::string Animal::getType() const
{
    return (_type);
}