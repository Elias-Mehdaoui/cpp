#include "../includes/Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name){
    std::cout << "Constructor called" << std::endl;
}

Zombie::~Zombie(){
    std::cout << _name << " has been destroyed\n";
}

void Zombie::announce()
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}