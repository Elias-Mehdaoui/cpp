#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form 
{
    private :
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExec;
    
    public :

        class GradeTooHighException : public std::exception
        {
            virtual const char* what() const throw() {
            return "Grade too high";
            }
        };

        class GradeTooLowException : public std::exception
        {
            virtual const char* what() const throw() {
                return "Grade too low";
            }
        };

        Form();
        Form(const std::string _name, const int _gradeToSign, const int _gradeToExec);
        Form(const Form& other);
        ~Form();
        Form& operator=(const Form& other);

        const std::string getName() const;
        int getSign() const;
        int getExec() const;
        bool getSigned() const;
        void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& form);


#endif