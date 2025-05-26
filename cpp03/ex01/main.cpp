#include "includes/ClapTrap.hpp"
#include "includes/ScavTrap.hpp"

int main() {
    std::cout << "\n===== ClapTrap Tests =====\n";
    {
        ClapTrap clap("CL4P-TP");
        clap.attack("Bandit");
        clap.takeDamage(5);
        clap.beRepaired(3);
    } // Destructor called here

    std::cout << "\n===== ScavTrap Tests =====\n";
    {
        ScavTrap scav("SC4V-TP");
        scav.attack("Psycho");
        scav.takeDamage(15);
        scav.beRepaired(10);
        scav.guardGate(); // Special ScavTrap function
    } // Destructor called here

    // std::cout << "\n===== Polymorphism Test =====\n";
    // {
    //     ClapTrap* ptr = new ScavTrap("POLY-TP");
    //     ptr->attack("Goliath"); // Should call ScavTrap's attack if virtual
    //     delete ptr; // Should call ScavTrap's destructor if ~ClapTrap is virtual
    // }

    std::cout << "\n===== Copy Assignment Test =====\n";
    {
        ScavTrap scav1("Original");
        ScavTrap scav2("Copy");
        scav2 = scav1;
        scav2.attack("Clone");
    }

    return 0;
}