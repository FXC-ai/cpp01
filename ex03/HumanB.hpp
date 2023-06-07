#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string	_name;
		Weapon*				_type;

	public:
		HumanB(std::string const name);
		~HumanB();
		void	attack();
		void	setWeapon(Weapon type);
};

#endif