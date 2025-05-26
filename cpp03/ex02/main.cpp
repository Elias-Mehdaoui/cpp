#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "\n===== Basic ClapTrap Test =====\n";
    {
        ClapTrap clap("CL4P-9000");
        clap.attack("Skag");
        clap.takeDamage(3);
        clap.beRepaired(2);
    } // Destructor called here

    std::cout << "\n===== ScavTrap Test =====\n";
    {
        ScavTrap scav("SC4V-TP");
        scav.attack("Bandit");
        scav.takeDamage(10);
        scav.beRepaired(5);
        scav.guardGate(); // ScavTrap special
    }

    std::cout << "\n===== FragTrap Test =====\n";
    {
        FragTrap frag("FR4G-TP");
        frag.attack("Psycho");
        frag.takeDamage(15);
        frag.beRepaired(8);
        frag.highFivesGuys(); // FragTrap special
    }

    // std::cout << "\n===== Polymorphism Test =====\n";
    // {
    //     ClapTrap* traps[3];
        
    //     traps[0] = new ClapTrap("BaseModel");
    //     traps[1] = new ScavTrap("Gatekeeper");
    //     traps[2] = new FragTrap("Exploder");

    //     for (int i = 0; i < 3; i++) {
    //         traps[i]->attack("Target");
    //         delete traps[i]; // Should call correct destructor if ~ClapTrap is virtual
    //         std::cout << "-----\n";
    //     }
    // }

    std::cout << "\n===== Copy Constructor Test =====\n";
    {
        FragTrap original("Original");
        FragTrap copy(original); // Copy constructor
        copy.attack("Clone");
    }

    return 0;
}