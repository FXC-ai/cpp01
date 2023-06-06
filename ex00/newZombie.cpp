#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie* newZombie(std::string name)
{
	Zombie*	newZomb;

	newZomb = new Zombie(name);

	return newZomb;
}