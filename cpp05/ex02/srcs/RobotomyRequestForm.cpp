#include "RobotomyRequestForm.hpp"
#include <cstdlib>


RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45), _target(NULL)
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("Robotomy Request Form", 72, 45), _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
        *this = other;
    return (*this);
}

bool RobotomyRequestForm::action(const Bureaucrat& executor) const
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

    int randInt = rand() % 2;

    std::cout << "BBBBBRRRrrrrrrr........" << std::endl;

    if (randInt % 2)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else 
        std::cout << _target << " Failed to robotomized" << std::endl;

    return (1);

}


