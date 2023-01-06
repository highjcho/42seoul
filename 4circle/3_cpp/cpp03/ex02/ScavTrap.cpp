/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:17:42 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/06 12:45:30 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	_hit = 100;
	_energy = 50;
	_attackDamage = 20;
	std::cout << SCAV << "[Create] Hi, I'm a default ScavTrap\n" << EOC;
}

ScavTrap::ScavTrap(const std::string& name)
: ClapTrap()
{
	_name = name;
	_hit = 100;
	_energy = 50;
	_attackDamage = 20;
	std::cout << SCAV << "[LOGIN] I'm " << name << "!! ";
	std::cout << "I'm a ScavTrap. I can be a gate keeper as well! Go! Go! \n\n" << EOC;
}

ScavTrap::ScavTrap(const ScavTrap &obj) {
	*this = obj;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &obj) {
	if (this != &obj) {
		_name = obj.getName();
		_hit = obj.getHit();
		_energy = obj.getEnergy();
		_attackDamage = obj.getAttackDamage();
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << SCAV << "[LOGOUT] Ooooops!! Scav " << _name << " out!\n" << EOC;
}

void ScavTrap::attack(const std::string& target) {
	std::cout << SCAV << "[Attack] ";
	if (_energy == 0 || _hit == 0) {
		std::cout << _name << " has no more power..\n";
		std::cout << "( Message ) " << _name << ": Sorry.. I can't attack anymore..\n\n" << EOC;
		delete this;
	}
	else {
		_energy -= 1;		
		std::cout << _name << " attacks " << target << "!!, causing " << _attackDamage << " points of damage!!\n";
		std::cout << "( Message ) Are you alright?? Haha!!\n" << EOC;
		ClapTrap::showStatus();
	}
}

void ScavTrap::guardGate() {
	std::cout << SCAV << "[Change Mode] ";
	if (_energy == 0 || _hit == 0) {
		std::cout << _name << " has no more power..\n";
		std::cout << "( Message ) " << _name << ": Sorry.. I can't change mode.. Bye..\n\n" << EOC;
	}
	std::cout << "Now " << _name << " in Gate Keeper Mode.\n\n" << EOC;
}