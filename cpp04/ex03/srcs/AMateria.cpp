#include "AMateria.hpp"

AMateria::AMateria() : _type("no type")
{
    std::cout << "AMateria::Constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
    std::cout << "AMateria::Constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type)
{
    std::cout << "AMateria::Copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
        _type = other._type;
    return (*this);
}

AMateria::~AMateria()
{
    std::cout << "AMateria::Destructor called" << std::endl;
}

std::string const & AMateria::getType() const 
{
    return (_type);
}