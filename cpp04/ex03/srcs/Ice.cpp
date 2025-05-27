#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice::Constructor called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other)
{
    std::cout << "Ice::copy Constructor called" << std::endl;
}

Ice::~Ice()
{
    std::cout << "Ice::Destructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
    if (this != &other)
        _type = other._type;
    return (*this);
}

Ice *Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
