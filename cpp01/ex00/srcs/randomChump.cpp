#include "../includes/Zombie.hpp"

void randomChump( std::string name )
{
    Zombie random(name);
    random.announce();
}
