#include "Bureaucrat.hpp"

int main() {
    // Test default constructor
    Bureaucrat b1;
    std::cout << b1 << std::endl;

    // Test parameterized constructor with valid grade
    try {
        Bureaucrat b2("Alice", 42);
        std::cout << b2 << std::endl;

        // Test grade increment
        b2.gradeInc();
        std::cout << "After increment: " << b2 << std::endl;

        // Test grade decrement
        b2.gradeDec();
        std::cout << "After decrement: " << b2 << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test parameterized constructor with too high grade
    try {
        Bureaucrat b3("Bob", 0);
    } catch (const std::exception& e) {
        std::cout << "Exception (too high): " << e.what() << std::endl;
    }

    // Test parameterized constructor with too low grade
    try {
        Bureaucrat b4("Charlie", 151);
    } catch (const std::exception& e) {
        std::cout << "Exception (too low): " << e.what() << std::endl;
    }

    // Test copy constructor and assignment operator
    Bureaucrat b5("David", 10);
    Bureaucrat b6 = b5; // copy constructor
    std::cout << "Copy constructed: " << b6 << std::endl;

    Bureaucrat b7;
    b7 = b5; // assignment operator
    std::cout << "Assigned: " << b7 << std::endl;

    // Test incrementing beyond limit
    try {
        Bureaucrat b8("Eve", 1);
        b8.gradeInc();
    } catch (const std::exception& e) {
        std::cout << "Exception (increment too high): " << e.what() << std::endl;
    }

    // Test decrementing beyond limit
    try {
        Bureaucrat b9("Frank", 150);
        b9.gradeDec();
    } catch (const std::exception& e) {
        std::cout << "Exception (decrement too low): " << e.what() << std::endl;
    }

    return 0;
}