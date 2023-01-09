/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:16:55 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/09 12:18:17 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
: ClapTrap("DIA")
{
	_name = "DIA";
	_hit = F_HIT;
	_energy = S_ENERGY;
	_attackDamage = F_ATTACK;
	std::cout << DIA << "[Create] Hi, I'm a default diamond!\n" << EOC;
}

DiamondTrap::DiamondTrap(const std::string& name)
: ClapTrap(name)
{
	_name = name;
	_hit = F_HIT;
	_energy = S_ENERGY;
	_attackDamage = F_ATTACK;
	std::cout << DIA << "[LOGIN] I'm " << _name << "!! ";
	std::cout << "I'm a DiamondTrap. I'm very confused. Who am I?? \n\n" << EOC;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) {
	*this = obj;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &obj) {
	if (this != &obj) {
		_name = obj.getName();
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

std::string DiamondTrap::getName() const{
	return _name;
}