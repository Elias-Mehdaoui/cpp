#include <iostream>
#include <string>

class Bureaucrat 
{
    private :
        const std::string _name;
        int _grade;
    
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
        
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        ~Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat& other);

        const std::string getName() const;
        int getGrade() const;
        void gradeInc();
        void gradeDec();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);