#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void testFormCreation() {
    std::cout << "\n--- TEST CREATION FORM ---\n";
    try {
        Form tooHigh("TopSecret", 0, 50);
        std::cout << "UNEXPECTED SUCCESS: " << tooHigh << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Expected error (high grade): " << e.what() << std::endl;
    }

    try {
        Form tooLow("Public", 151, 150);
        std::cout << "UNEXPECTED SUCCESS: " << tooLow << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Expected error (low grade): " << e.what() << std::endl;
    }

    try {
        Form valid("Contrat", 50, 25);
        std::cout << "Valid form created: " << valid << std::endl;
    } catch (const std::exception& e) {
        std::cout << "UNEXPECTED ERROR: " << e.what() << std::endl;
    }
}

void testSigning() {
    std::cout << "\n--- TEST SIGNATURE ---\n";
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Stagiaire", 150);
        Form important("Important", 10, 5);

        intern.signForm(important);
        boss.signForm(important);
        
        std::cout << important << std::endl;
    } catch (const std::exception& e) {
        std::cout << "UNEXPECTED ERROR IN SIGNING TEST: " << e.what() << std::endl;
    }
}

void testEdgeCases() {
    std::cout << "\n--- TEST CAS LIMITES ---\n";
    try {
        Bureaucrat midLevel("Employee", 75);
        Form edgeForm("Edge", 75, 75);

        midLevel.signForm(edgeForm);
        std::cout << edgeForm << std::endl;
    } catch (const std::exception& e) {
        std::cout << "UNEXPECTED ERROR IN EDGE CASE: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "===== TEST CPP05 EX01 (Form & Bureaucrat) =====\n";

    try {
        testFormCreation();
        testSigning();
        testEdgeCases();
    } catch (const std::exception& e) {
        std::cout << "CRITICAL UNCAUGHT ERROR: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}