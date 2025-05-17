#include "includes/Zombie.hpp"

void randomChump( std::string name );
Zombie* newZombie( std::string name);

int main()
{
    Zombie *test = newZombie("la bete");
    test->announce();
    delete test;

    randomChump("random chump");
}