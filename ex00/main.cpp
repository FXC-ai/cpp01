#include "Zombie.hpp"
#include <string>
#include <iostream>

int main ()
{
	
	Zombie	*Christina;

	randomChump("Victor");

	Christina = newZombie("Christina");

	Christina->announce();

	delete Christina;

	return 0;
}