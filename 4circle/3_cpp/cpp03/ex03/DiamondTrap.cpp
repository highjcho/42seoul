/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:16:55 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/12/26 14:44:22 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << DIA << "You can't call this" << EOC;
}

DiamondTrap::DiamondTrap(const std::string& name)
: ClapTrap(name)
{
	_name = name;
	_hit = FragTrap::_hit;
	_energy = ScavTrap::_energy;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << DIA << "[LOGIN] I'm " << name << "!! ";
	std::cout << "I'm a DiamondTrap. I'm very confused. Who am I?? \n\n" << EOC;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) {
	*this = obj;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &obj) {
	if (this != &obj) {
		_hit = obj.getHit();
		_energy = obj.getEnergy();
		_attackDamage = obj.getAttackDamage();
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << DIA << "[LOGOUT] Ooooops!! Diamond " << _name << " out!\n" << EOC;
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << DIA << "[CONFUSED] I have 2 names. Frist is " << ClapTrap::_name << " and second is " << _name << ". Who am I?\n\n" << EOC;
}