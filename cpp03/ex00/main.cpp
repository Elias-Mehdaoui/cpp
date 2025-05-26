#include "includes/ClapTrap.hpp"

int main ()
{
	ClapTrap david("david"), goliath("goliath");
	david.attack(goliath.getName());
	goliath.takeDamage(10);
	david.attack(goliath.getName());
	goliath.takeDamage(10);
}