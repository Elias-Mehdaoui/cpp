#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat::Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "WrongCat::Copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat::Destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
        _type = other._type;
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "Meow Meow" << std::endl;
}