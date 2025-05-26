#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog::Constructor called" << std::endl;
}
Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog::Copy constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog::Destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
        _type = other._type;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof" << std::endl;
}