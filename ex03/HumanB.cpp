#include <string>
#include <iostream>
#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB (std::string const name) : _name(name)
{
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon type)
{
	this->_type = &type;
}


void	HumanB::attack()
{
	std::cout << this->_name + " attacks with their " + this->_type->getType() << std::endl;
}