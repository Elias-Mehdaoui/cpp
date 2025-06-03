#include "AForm.hpp"

AForm::AForm() : _name("unknown"), _signed(0), _sign(1), _exec(1)
{
}

AForm::AForm(const std::string name, const int sign, const int exec) : _name(name), _signed(0), _sign(sign), _exec(exec)
{
    if (_sign < 1 || _exec < 1)
        throw GradeTooHighException();
    else if (_sign > 150 || _exec > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed), _sign(other._sign), _exec(other._exec)
{
}

AForm::~AForm()
{
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        _signed = other._signed;
    return (*this);
}

const std::string AForm::getName() const 
{
    return (_name);
}

int AForm::getSign() const
{
    return (_sign);
}

int AForm::getExec() const
{
    return (_exec);
}

bool AForm::getSigned() const
{
    return (_signed);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= _sign)
        _signed = 1;
    else
        throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > _exec)
        throw GradeTooLowException();
    else if (!_signed)
        throw NotSignedException();
}


std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << form.getName() << ", form grade required to sign " << form.getSign() << ", form grade required to exec " << form.getExec() << ", form is signed ? " << form.getSigned() << std::endl;
    return os;
}

