#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _materias(new AMateria*[4]())
{
    std::cout << "MateriaSource::Constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) : _materias(new AMateria*[4]())
{
    for (int i = 0; i < 4; i++)
    {
        if (other._materias[i])
            _materias[i] = other._materias[i]->clone();
    }
    std::cout << "MateriaSource::Copy constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i])
            delete _materias[i];
    }
    delete[] _materias;
    std::cout << "MateriaSource::Destructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
 if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_materias[i])
                delete _materias[i];
        }
        delete[] _materias;
        _materias = new AMateria*[4]();
        for (int i = 0; i < 4; i++)
        {
            if (other._materias[i])
                _materias[i] = other._materias[i]->clone();
        }
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria* materia)
{
    for (int i = 0; i < 4; i++)
    {
        if (!_materias[i])
        {
            _materias[i] = materia;
            return;
        }
    }
    std::cout << "Materia Source inventory is full" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i] && _materias[i]->getType() == type)
            return (_materias[i]->clone());
    }
    return (0);
}

