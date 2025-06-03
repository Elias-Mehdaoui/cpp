#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
    *this = other;
}

Intern::~Intern()
{
}

Intern& Intern::operator=(const Intern& other)
{
    if (this != &other)
        *this = other;
    return (*this);
}


AForm* Intern::NewRobotomyRequestForm(std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm* Intern::NewPresidentialPardonForm(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::NewShrubberyCreationForm(std::string target)
{
    return (new ShrubberyCreationForm(target));
}
AForm *Intern::makeForm(std::string name, std::string target)
{
        struct forms {
        std::string name;
        AForm* (Intern::*function)(std::string target);
    };

    forms forms_list[] = {
        {"shrubbery creation", &Intern::NewShrubberyCreationForm },
        {"presidential pardon", &Intern::NewPresidentialPardonForm},
        {"robotomy request", &Intern::NewRobotomyRequestForm},
    };

    for (int i = 0; i < 3; i++)
    {
        if (name == forms_list[i].name)
        {
            std::cout << "test";
            return (this->*forms_list[i].function)(target);
        }
    }
    std::cout << "Please enter a known form name" << std::endl;
    return (NULL);
}