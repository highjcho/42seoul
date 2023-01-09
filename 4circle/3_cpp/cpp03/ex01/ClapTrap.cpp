/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:01:35 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/09 12:16:24 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: _hit(10), _energy(10), _attackDamage(0)
{
	std::cout << CLAP << "[Create] Hi, I'm a parent ClapTrap!\n" << EOC;
}

ClapTrap::ClapTrap(const std::string& name)
: _name(name), _hit(10), _energy(10), _attackDamage(0)
{
	std::cout << CLAP << "[LOGIN] I'm " << _name << "!! ";
	std::cout << "But I'm a ClapTrap.. I can't give any damage to enemies. Do you really want me..?\n\n" << EOC;
}

ClapTrap::ClapTrap(const ClapTrap &obj) {
	*this = obj;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &obj) {
	if (this != &obj) {
		_name = obj.getName();
		_hit = obj.getHit();
		_energy = obj.getEnergy();
		_attackDamage = obj.getAttackDamage();
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << CLAP << "[LOGOUT] Ooooops!! Clap " << _name << " out!\n\n" << EOC;
}

void ClapTrap::attack(const std::string& target) {
	std::cout << CLAP << "[Attack] ";
	if (_energy == 0 || _hit == 0) {
		std::cout << _name << " has no more power..\n";
		std::cout << "( Message ) " << _name << ": Sorry.. I can't attack anymore..\n\n" << EOC;
	}
	else {
		_energy -= 1;		
		std::cout << CLAP << _name << " attacks " << target << "!!, causing " << _attackDamage << " points of damage!!\n" << EOC;
		ClapTrap::showStatus();
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "[Damage] ";
	if (_hit <= amount) {
		_hit = 0;
		std::cout << _name << " has no more power..\n";
		std::cout << "( Message ) " << _name << ": Sorry.. I can't survive from this attack..\n\n";
	}
	else {
		_hit -= amount;
		std::cout << _name << " got " << amount << " points damage!!\n";
		ClapTrap::showStatus();
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "[Repair] ";
	if (_energy == 0 || _hit == 0) {
		std::cout << _name << " has no more power..\n";
		std::cout << "( Message ) " << _name << ": Sorry.. I can't repair anymore..\n\n" << EOC;
	}
	else {
		_hit += amount;
		_energy -= 1;
		std::cout << _name << " is repairing!!\n";
		ClapTrap::showStatus();
	}
}

std::string ClapTrap::getName() const {
	return _name;
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
	std::cout << "Hit points " << _hit << ", Energy points " << _energy << "\n\n";
}