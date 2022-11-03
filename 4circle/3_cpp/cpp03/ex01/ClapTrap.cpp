/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:01:35 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/11/03 14:14:19 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() { // 못부르게 해야 하나?
	std::cout << "[Create] I'm in!\n";
}

ClapTrap::ClapTrap(const std::string name) 
: _hit(10), _energy(10), _attackDamage(0)
{

	_name = name;
	std::cout << "[Create] I'm " << name << "!! ";
	std::cout << "But I'm a ClapTrap.. I can't give any damage to enemies. Do you really want me..?\n\n";
}

ClapTrap::ClapTrap(const ClapTrap &obj) {
	*this = obj;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &obj) {
	if (this != &obj) {
		_hit = obj.getHit();
		_energy = obj.getEnergy();
		_attackDamage = obj.getAttackDamage();
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "[Died] Ooooops!! " << _name << " out!\n";
}

void ClapTrap::attack(const std::string& target) {
	std::cout << "\n[Attack] ";
	if (_energy == 0) {
		std::cout << _name << " has no more energy points..\n";
		std::cout << "( Message ) " << _name << ": Sorry.. I can't attack anymore..\n\n";
		delete this;
	}
	else {
		_energy -= 1;		
		std::cout << _name << " attacks " << target << "!!, causing " << _attackDamage << " points of damage!!\n";
		ClapTrap::showStatus();
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "\n[Damage] ";
	if (_hit <= amount) {
		std::cout << _name << " has no more hit points..\n";
		std::cout << "( Message ) " << _name << ": Sorry.. I can't survive from this attack..\n\n";
		delete this;
	}
	else {
		_hit -= amount;
		std::cout << _name << " got " << amount << " points damage!!\n";
		ClapTrap::showStatus();
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "\n[Repair] ";
	if (_energy == 0) {
		std::cout << _name << " has no more energy points..\n";
		std::cout << "( Message ) " << _name << ": Sorry.. I can't reapir anymore..\n\n";
		delete this;
	}
	else {
		_hit += amount;
		_energy -= 1;
		std::cout << _name << " is repairing!!\n";
		ClapTrap::showStatus();
	}
}

unsigned int ClapTrap::getHit() const {
	return _hit;
}

unsigned int ClapTrap::getEnergy() const {
	return _energy;
}

unsigned int ClapTrap::getAttackDamage() const {
	return _attackDamage;
}

void ClapTrap::showStatus() const {
	std::cout << "( " << _name << "'s status ) => ";
	std::cout << "Hit points " << _hit << ", Energy points " << _energy << "\n";
}