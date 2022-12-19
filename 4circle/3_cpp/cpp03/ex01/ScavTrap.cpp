/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:17:42 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/12/19 19:45:41 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() { // 어떻게 해해야야하하지지? 없없애버려? ㅜ구현하지마? 프로텍티드로 내내려려?
	std::cout << "You can't call this";
}

ScavTrap::ScavTrap(const std::string& name)
: ClapTrap("Scav " + name + "'s Parent")
{
	_name = name;
	_hit = 100;
	_energy = 50;
	_attackDamage = 20;
	std::cout << "[Create] I'm " << name << "!! ";
	std::cout << "I'm a ScavTrap. I can be a gate keeper as well! Go! Go! \n\n";
}

ScavTrap::ScavTrap(const ScavTrap &obj) {
	*this = obj;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &obj) {
	if (this != &obj) {
		_hit = obj.getHit();
		_energy = obj.getEnergy();
		_attackDamage = obj.getAttackDamage();
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "\n[Died] Ooooops!! Scav " << _name << " out!\n";
}

void ScavTrap::attack(const std::string& target) {
	std::cout << "\n[Attack] ";
	if (_energy == 0) {
		std::cout << _name << " has no more energy points..\n";
		std::cout << "( Message ) " << _name << ": Sorry.. I can't attack anymore..\n\n";
		delete this;
	}
	else {
		_energy -= 1;		
		std::cout << _name << " attacks " << target << "!!, causing " << _attackDamage << " points of damage!!\n";
		std::cout << "( Message ) Are you alright?? Haha!!\n";
		ClapTrap::showStatus();
	}
}

void ScavTrap::guardGate() {
	std::cout << "\n[Change Mode] ";
	if (_energy == 0 || _hit == 0) {
		std::cout << _name << " has no more energy or hit point..\n";
		std::cout << "( Message ) " << _name << ": Sorry.. I can't change mode.. Bye..\n\n";
	}
	std::cout << "Now " << _name << " in Gate Keeper Mode.\n";
}