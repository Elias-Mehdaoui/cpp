#include "AForm.hpp"

class RobotomyRequestForm : public AForm 
{
    private :
        std::string _target;
    
    public :
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        bool action(Bureaucrat const & executor) const;
};