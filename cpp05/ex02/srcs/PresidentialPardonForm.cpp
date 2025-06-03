#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5), _target(NULL)
{

}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("Presidential Pardon Form", 25, 5), _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
        *this = other;
    return (*this);
}

bool PresidentialPardonForm::action(const Bureaucrat& executor) const
{
    try 
    {
        this->execute(executor);
    }
    catch (const std::exception& e)
    {
        std::cout << "Error : " << e.what() << std::endl;
        return (0);
    }

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    return (1);
}


