#include "Form.hpp"

Form::Form() : _name("unknown"), _signed(0), _gradeToSign(1), _gradeToExec(1)
{
}
Form::Form(const std::string name, const int gradeToSign, const int gradeToExec) : _name(name), _signed(0), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{

}
Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{

}

Form::Fo
