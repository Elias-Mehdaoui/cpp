#include "includes/AMateria.hpp"
#include "includes/Character.hpp"
#include "includes/Ice.hpp"
#include "includes/Cure.hpp"
#include <cassert>

void testBasicFunctionality() {
    std::cout << "\n=== TEST BASIC FUNCTIONALITY ===\n";
    ICharacter* hero = new Character("Hero");
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();
    
    hero->equip(ice);
    hero->equip(cure);
    
    ICharacter* enemy = new Character("Enemy");
    hero->use(0, *enemy);  // Should use ice
    hero->use(1, *enemy);  // Should use cure
    
    // Test unequip
    hero->unequip(0);
    hero->unequip(1);
    
    delete enemy;
    delete hero;
    // Note: unequipped materias should be handled elsewhere to avoid leaks
}

void testInventoryLimits() {
    std::cout << "\n=== TEST INVENTORY LIMITS ===\n";
    Character player("Player");
    
    // Fill inventory
    for (int i = 0; i < 4; ++i) {
        player.equip(new Ice());
    }
    
    // Try to equip fifth item
    AMateria* extra = new Cure();
    player.equip(extra);  // Should fail (no message expected per subject)
    delete extra;  // Since it couldn't be equipped
    
    // Verify first 4 slots work
    Character dummy("Dummy");
    for (int i = 0; i < 4; ++i) {
        player.use(i, dummy);
    }
}

void testCopyAndAssignment() {
    std::cout << "\n=== TEST COPY AND ASSIGNMENT ===\n";
    
    // Setup original character
    Character original("Original");
    original.equip(new Ice());
    original.equip(new Cure());
    
    // Test copy constructor - should create independent copy
    Character copy(original);
    
    // Both should work initially
    std::cout << "Original using materias:\n";
    original.use(0, copy);  // Ice
    original.use(1, copy);  // Cure
    
    std::cout << "Copy using materias:\n";
    copy.use(0, original);  // Ice (copy)
    copy.use(1, original);  // Cure (copy)
    
    // Now modify original - should not affect copy
    std::cout << "Unequipping from original...\n";
    original.unequip(0);    // Remove ice from original
    original.unequip(1);    // Remove cure from original
    
    // Verify copy still has its own materias
    std::cout << "Copy should still have materias:\n";
    copy.use(0, original);  // Should still work (independent copy)
    copy.use(1, original);  // Should still work
    
    // Verify original's slots are empty
    std::cout << "Original's slots should be empty:\n";
    original.use(0, copy);  // Should do nothing (slot 0 empty)
    original.use(1, copy);  // Should do nothing (slot 1 empty)
    
    // Test assignment operator
    Character assigned("AssignedBefore");
    assigned = copy;  // Should make a new copy
    
    std::cout << "Assigned using materias:\n";
    assigned.use(0, original);  // Should work
    assigned.use(1, original);  // Should work
    
    // Modify copy - should not affect assigned
    copy.unequip(0);
    copy.unequip(1);
    
    std::cout << "Assigned should still have materias:\n";
    assigned.use(0, copy);  // Should still work
    assigned.use(1, copy);  // Should still work
}

void testMateriaCloning() {
    std::cout << "\n=== TEST MATERIA CLONING ===\n";
    Ice originalIce;
    AMateria* clonedIce = originalIce.clone();
    
    Cure originalCure;
    AMateria* clonedCure = originalCure.clone();
    
    Character caster("Caster");
    Character target("Target");
    
    caster.equip(clonedIce);
    caster.equip(clonedCure);
    caster.use(0, target);
    caster.use(1, target);
}

void testEdgeCases() {
    std::cout << "\n=== TEST EDGE CASES ===\n";
    Character ch("Tester");
    
    // Use empty slot
    ch.use(0, ch);  // Should do nothing
    
    // Unequip empty slot
    ch.unequip(3);  // Should do nothing
    
    // Equip NULL
    ch.equip(NULL);  // Should do nothing
    
    // Copy empty character
    Character empty;
    Character emptyCopy(empty);
    emptyCopy.use(2, empty);  // Should do nothing
}

void testMateriaManagement() {
    std::cout << "\n=== TEST MATERIA MANAGEMENT ===\n";
    Character ch("Owner");
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();
    
    ch.equip(ice);
    ch.equip(cure);
    
    // Unequip and reuse materia
    ch.unequip(0);
    Character ch2("NewOwner");
    ch2.equip(ice);  // Reuse unequipped materia
    
    // Verify it works in new owner
    ch2.use(0, ch);
    
    // Cleanup
        
}

int main() {
    // testBasicFunctionality();
    // testInventoryLimits();
    // testCopyAndAssignment();
    // testMateriaCloning();
    // testEdgeCases();
    testMateriaManagement();
    
    std::cout << "\nAll tests completed!\n";
    return 0;
}