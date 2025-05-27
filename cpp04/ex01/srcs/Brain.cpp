#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; i++)
        _ideas[i] = "";
    std::cout << "Brain::constructor called" << std::endl;
}

Brain::Brain(const Brain& other) 
{
    for (int i = 0; i < 100; i++)
        _ideas[i] = other._ideas[i];
    std::cout << "Brain::Copy constrcutor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
    if (this != &other)
    {    
        for (int i = 0; i < 100; i++)
            _ideas[i] = other._ideas[i];
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain::Destructor called" << std::endl;
}

void Brain::setIdea(int index, std::string idea)
{
    this->_ideas[index] = idea;
}

std::string Brain::getIdea(int index)
{
    return (this->_ideas[index]);
}

