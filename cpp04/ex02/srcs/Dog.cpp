#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain)
{
    std::cout << "Dog::Constructor called" << std::endl;
}
Dog::Dog(const Dog& other) : Animal(other), _brain(new Brain(*other._brain))
{
    std::cout << "Dog::Copy constructor called" << std::endl;
}

Dog::~Dog()
{
    delete _brain;
    std::cout << "Dog::Destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        _type = other._type;
        _brain = new Brain(*other._brain);
    }
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof" << std::endl;
}

Brain* Dog::getBrain()
{
    return (this->_brain);
}
