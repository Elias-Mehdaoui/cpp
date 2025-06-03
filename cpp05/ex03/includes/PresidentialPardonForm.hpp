#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private :
        std::string _target;

    public :
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        bool action(Bureaucrat const & executor) const;
};