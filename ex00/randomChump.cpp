#include "Zombie.hpp"
#include <string>
#include <iostream>

void randomChump(std::string name)
{
	Zombie	newZomb;

	newZomb = Zombie(name);
	newZomb.announce();
}