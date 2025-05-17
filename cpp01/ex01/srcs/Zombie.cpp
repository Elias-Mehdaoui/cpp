#include "../includes/Zombie.hpp"

Zombie::Zombie(){
    std::cout << "Constructor called" << std::endl;
}

Zombie::~Zombie(){
    std::cout << _name << " has been destroyed\n";
}

void Zombie::announce()
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}