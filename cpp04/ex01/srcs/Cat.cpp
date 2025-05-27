#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain)
{
    std::cout << "Cat::Constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other._brain))
{
    std::cout << "Cat::Copy constructor called" << std::endl;
}

Cat::~Cat()
{
    delete _brain;   
    std::cout << "Cat::Destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        _type = other._type;
        _brain = new Brain(*other._brain);
    }
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow" << std::endl;
}

Brain* Cat::getBrain()
{
    return (this->_brain);
}
