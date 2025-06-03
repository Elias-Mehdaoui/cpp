#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm 
{
    private :
        const std::string _name;
        bool _signed;
        const int _sign;
        const int _exec;
    
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

        class NotSignedException : public std::exception
        {
            virtual const char* what() const throw() {
                return "Form must be signed in order to get executed";
            }
        };

        class AlreadySigned : public std::exception
        {
            virtual const char* what() const throw() {
                return "Form can be signed only once";
            }
        };

        AForm();
        AForm(const std::string name, const int sign, const int exec);
        AForm(const AForm& other);
        virtual ~AForm();
        AForm& operator=(const AForm& other);

        const std::string getName() const;
        int getSign() const;
        int getExec() const;
        bool getSigned() const;
        void beSigned(const Bureaucrat& bureaucrat);
        void execute(Bureaucrat const & executor) const;
        virtual bool action(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);


#endif