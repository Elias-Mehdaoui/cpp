#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

void testFormExecution(Bureaucrat& bureaucrat, AForm& form) {
    std::cout << "\n--- Testing " << form.getName() << " ---\n";
    try {
        bureaucrat.signForm(form);
        bureaucrat.executeForm(form);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "===== TESTING CPP05 EX02 (FORMS) =====\n";

    // Create bureaucrats with different grades
    Bureaucrat highRank("High Rank", 1);
    Bureaucrat midRank("Mid Rank", 100);
    Bureaucrat lowRank("Low Rank", 150);

    // Create forms
    PresidentialPardonForm pardon("Target1");
    RobotomyRequestForm robotomy("Target2");
    ShrubberyCreationForm shrubbery("Target3");

    // Test cases
    std::cout << "\n====== HIGH RANK (Grade 1) ======\n";
    testFormExecution(highRank, pardon);
    testFormExecution(highRank, robotomy);
    testFormExecution(highRank, shrubbery);

    std::cout << "\n====== MID RANK (Grade 50) ======\n";
    testFormExecution(midRank, pardon);    // Should fail (sign:25, exec:5)
    testFormExecution(midRank, robotomy);  // Should sign but fail exec (grade 45 needed)
    testFormExecution(midRank, shrubbery); // Should work (sign:145, exec:137)

    std::cout << "\n====== LOW RANK (Grade 150) ======\n";
    testFormExecution(lowRank, pardon);    // Should fail all
    testFormExecution(lowRank, robotomy);  // Should fail all
    testFormExecution(lowRank, shrubbery); // Should fail all

    // Edge case: Execute unsigned form
    std::cout << "\n====== EDGE CASE: UNSIGNED FORM ======\n";
    PresidentialPardonForm unsignedForm("Unauthorized");
    try {
        highRank.executeForm(unsignedForm); // Should throw "not signed"
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}