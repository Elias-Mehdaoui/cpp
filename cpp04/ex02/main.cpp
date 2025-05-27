#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    // 1. Test: Animal cannot be instantiated (uncomment to verify)
    // Animal abstractAnimal;  // Should FAIL (abstract class)

    // 2. Create Dog and Cat (polymorphically stored in Animal* array)
    std::cout << "----- Constructing Animals -----" << std::endl;
    const int SIZE = 4;
    Animal* animals[SIZE];

    for (int i = 0; i < SIZE; i++) {
        if (i % 2 == 0)
            animals[i] = new Dog();  // Even index = Dog
        else
            animals[i] = new Cat();  // Odd index = Cat
    }

    // 3. Test deep copies
    std::cout << "\n----- Testing Deep Copies -----" << std::endl;
    Dog dog1;
    Dog dog2(dog1);  // Should deep copy Brain
    Cat cat1;
    Cat cat2(cat1);  // Should deep copy Brain

    // 4. Test polymorphism
    std::cout << "\n----- Testing Polymorphism -----" << std::endl;
    for (int i = 0; i < SIZE; i++) {
        animals[i]->makeSound();  // Should bark or meow
    }

    // 5. Cleanup
    std::cout << "\n----- Deleting Animals -----" << std::endl;
    for (int i = 0; i < SIZE; i++) {
        delete animals[i];  // Should call Dog/Cat destructor
    }

    return 0;
}