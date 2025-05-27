#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure::Constructor called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
    std::cout << "Cure::copy Constructor called" << std::endl;
}

Cure::~Cure()
{
    std::cout << "Cure::Destructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
    if (this != &other)
        _type = other._type;
    return (*this);
}

Cure* Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}