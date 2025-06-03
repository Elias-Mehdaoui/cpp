#include "AForm.hpp"

class Intern
{
    public :
        Intern();
        Intern(const Intern& other);
        ~Intern();
        Intern& operator=(const Intern& other);
        AForm* makeForm(std::string name, std::string target);
        AForm* NewRobotomyRequestForm(std::string target);
        AForm* NewPresidentialPardonForm(std::string target);
        AForm* NewShrubberyCreationForm(std::string target);
};