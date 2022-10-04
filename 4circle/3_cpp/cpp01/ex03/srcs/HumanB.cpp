#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	_name = name;
}

void	HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}

void	HumanB::attack() {
	if (!_weapon)
		std::cout << _name << " doesn' take a weapon!!!\n";
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}