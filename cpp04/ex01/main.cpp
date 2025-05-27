#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    std::cout << "----- Constructing Animals -----" << std::endl;
    const int ARRAY_SIZE = 6;
    Animal* animals[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n----- Testing Deep Copies -----" << std::endl;
    Dog dog1;
    Dog dog2(dog1);
    Cat cat1;
    Cat cat2(cat1);

    dog1.getBrain()->setIdea(0, "Original Dog's Idea");
    dog2.getBrain()->setIdea(0, "Copied Dog's Idea");
    cat1.getBrain()->setIdea(0, "Original Cat's Idea"); 
    cat2.getBrain()->setIdea(0, "Copied Cat's Idea");

    std::cout << "\n----- Brain Content Check -----" << std::endl;
    std::cout << "Dog1 Idea 0: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 Idea 0: " << dog2.getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat1 Idea 0: " << cat1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat2 Idea 0: " << cat2.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n----- Deleting Animals -----" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        delete animals[i];
    }

    return 0;
}