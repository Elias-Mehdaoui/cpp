#include "Form.hpp"

Form::Form() : _name("unknown"), _signed(0), _gradeToSign(1), _gradeToExec(1)
{
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExec) : _name(name), _signed(0), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
    if (_gradeToSign < 1 || _gradeToExec < 1)
        throw GradeTooHighException();
    else if (_gradeToSign > 150 || _gradeToExec > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
}

Form::~Form()
{
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        _signed = other._signed;
    return (*this);
}

const std::string Form::getName() const 
{
    return (_name);
}

int Form::getSign() const
{
    return (_gradeToSign);
}

int Form::getExec() const
{
    return (_gradeToExec);
}

bool Form::getSigned() const
{
    return (_signed);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= _gradeToSign)
        _signed = 1;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << form.getName() << ", form grade required to sign " << form.getSign() << ", form grade required to exec " << form.getExec() << ", form is signed ? " << form.getSigned() << std::endl;
    return os;
}

