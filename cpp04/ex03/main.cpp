#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <iostream>

void testBasicFunctionality() {
    std::cout << "\n==== TEST BASIC FUNCTIONALITY ====\n";
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    AMateria* tmp;
    
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
    delete src;
}

void testInventoryLimits() {
    std::cout << "\n==== TEST INVENTORY LIMITS ====\n";
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    
    Character hero("Hero");
    AMateria* materias[4];
    
    // Fill inventory with created materias
    for (int i = 0; i < 4; i++) {
        materias[i] = src->createMateria("ice");
        hero.equip(materias[i]);
    }
    
    // Try to overfill
    AMateria* extra = src->createMateria("ice");
    hero.equip(extra); // Should fail (no output expected)
    delete extra; // Cleanup
    
    // Use all slots
    Character target("Target");
    for (int i = 0; i < 4; i++) {
        hero.use(i, target);
    }
    
    delete src;
}

void testMateriaSourceLearning() {
    std::cout << "\n==== TEST MATERIA SOURCE LEARNING ====\n";
    MateriaSource src;
    
    // Learn maximum (4) materias
    src.learnMateria(new Ice());
    src.learnMateria(new Cure());
    src.learnMateria(new Ice());
    src.learnMateria(new Cure());
    
    // Try to learn beyond capacity
    AMateria* extra = new Ice();
    src.learnMateria(extra); // Should fail (no output expected)
    delete extra;
    
    // Verify creation
    AMateria* ice = src.createMateria("ice");
    AMateria* cure = src.createMateria("cure");
    AMateria* unknown = src.createMateria("fire"); // Should return NULL
    
    Character dummy("Dummy");
    if (ice) {
        dummy.equip(ice);
        dummy.use(0, dummy);
    }
    if (cure) {
        dummy.equip(cure);
        dummy.use(1, dummy);
    }
    if (!unknown) {
        std::cout << "Unknown materia type correctly returns NULL\n";
    }
}

void testDeepCopies() {
    std::cout << "\n==== TEST DEEP COPIES ====\n";
    MateriaSource src;
    src.learnMateria(new Ice());
    src.learnMateria(new Cure());
    
    Character original("Original");
    original.equip(src.createMateria("ice"));
    original.equip(src.createMateria("cure"));
    
    // Test copy constructor
    Character copy(original);
    copy.use(0, original);
    copy.use(1, original);
    
    // Test assignment
    Character assigned("Assigned");
    assigned = original;
    assigned.use(0, original);
    assigned.use(1, original);
    
    // Verify independence
    original.unequip(0);
    copy.use(0, original); // Should still work (independent copy)
}

void testEdgeCases() {
    std::cout << "\n==== TEST EDGE CASES ====\n";
    MateriaSource src;
    Character dummy("Dummy");
    
    // Use empty slots
    dummy.use(0, dummy);
    dummy.use(3, dummy);
    
    // Unequip empty slots
    dummy.unequip(2);
    
    // Equip NULL
    dummy.equip(NULL);
    
    // Create from empty source
    AMateria* m = src.createMateria("ice");
    if (!m) {
        std::cout << "Empty source correctly returns NULL\n";
    }
}

int main() {
    testBasicFunctionality();
    testInventoryLimits();
    testMateriaSourceLearning();
    testDeepCopies();
    testEdgeCases();
    
    std::cout << "\n==== ALL TESTS COMPLETED ====\n";
    return 0;
}