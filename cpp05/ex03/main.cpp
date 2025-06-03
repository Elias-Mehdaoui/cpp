#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

void testForm(AForm* form, Bureaucrat& signer, Bureaucrat& executor) {
    if (!form) return;
    
    try {
        std::cout << form->getName() << " test:\n";
        signer.signForm(*form);
        executor.executeForm(*form);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << '\n';
    }
    delete form;
    std::cout << "------------------------------\n";
}

void testInternScenario(Intern& intern, const std::string& formName, 
                      const std::string& target, Bureaucrat& signer, Bureaucrat& executor) {
    std::cout << "\n Testing: \"" << formName << "\" for target \"" << target << "\"\n";
    AForm* form = intern.makeForm(formName, target);
    if (form) {
        std::cout << " Intern created " << form->getName() << std::endl;
        testForm(form, signer, executor);
    } else {
        std::cout << " Intern failed to create \"" << formName << "\"\n";
    }
}

int main() {
    Intern  intern;
    Bureaucrat president("President", 1);
    Bureaucrat director("Director", 40);
    Bureaucrat internBureaucrat("Junior", 150);

    // Valid forms
    testInternScenario(intern, "shrubbery creation", "Central Park", president, president);
    testInternScenario(intern, "robotomy request", "Bender", director, president);
    testInternScenario(intern, "presidential pardon", "Zaphod", president, president);

    // Edge cases
    testInternScenario(intern, "shrubbery creation", "Home", internBureaucrat, internBureaucrat);
    testInternScenario(intern, "unknown form", "target", president, president);
    testInternScenario(intern, "", "no_target", director, director);

    return 0;
}