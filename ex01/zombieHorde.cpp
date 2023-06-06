#include "Zombie.hpp"
#include <string>
#include <iostream>


Zombie* zombieHorde(int N, std::string name)
{
	Zombie*	horde;

	horde = new Zombie[N];

	return horde;
}