#include "includes/Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main()
{
    Zombie *zombie_array = zombieHorde(10, "la bete");
    for (int i = 0; i < 10; i++)
        zombie_array[i].announce();
    delete[] zombie_array;
}