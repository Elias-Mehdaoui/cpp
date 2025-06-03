#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("unknown"), _grade(1)
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        _grade = other._grade;
    return (*this);
}

const std::string Bureaucrat::getName() const 
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

void Bureaucrat::gradeInc()
{
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--;
}


void Bureaucrat::gradeDec()
{
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(AForm& form)
{
    if (form.getSigned())
    {
        std::cout << _name << " couldn't sign " << form.getName() << " because the form is already signed" << std::endl  ;
        return ;
    }
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << _name << " couldn't sign " << form.getName() << " because his grade isn't high enough" << std::endl  ;
    }
}

void Bureaucrat::executeForm(AForm const & form)
{
    if (form.action(*this))
        std::cout << _name << " executed " << form.getName() << std::endl;
    else
        std::cout << _name << " couldn't execute " << form.getName() << std::endl;
}



std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat) {
    os << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << ".";
    return os;
}

