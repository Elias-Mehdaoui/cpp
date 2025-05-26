#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat::Constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat::Copy constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat::Destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
        _type = other._type;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow" << std::endl;
}