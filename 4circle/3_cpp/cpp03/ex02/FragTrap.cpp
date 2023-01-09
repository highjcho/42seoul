/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:17:42 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/09 11:54:24 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
	_name = "FRAG";
	_hit = 100;
	_energy = 100;
	_attackDamage = 30;
	std::cout << FRAG << "[Create] Hi, I'm a default FragTrap!\n" << EOC;
}

FragTrap::FragTrap(const std::string& name)
: ClapTrap()
{
	_name = name;
	_hit = 100;
	_energy = 100;
	_attackDamage = 30;
	std::cout << FRAG << "[LOGIN] I'm " << name << "!! ";
	std::cout << "I'm a FragTrap. Keep your chin up guys!! \n\n" << EOC;
}

FragTrap::FragTrap(const FragTrap &obj) {
	*this = obj;
}

FragTrap& FragTrap::operator=(const FragTrap &obj) {
	if (this != &obj) {
		_name = obj.getName();
		_hit = obj.getHit();
		_energy = obj.getEnergy();
		_attackDamage = obj.getAttackDamage();
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << FRAG << "[LOGOUT] Ooooops!! Frag " << _name << " out!\n" << EOC;
}

void FragTrap::attack(const std::string& target) {
	std::cout << FRAG << "[Attack] ";
	if (_energy == 0 || _hit == 0) {
		std::cout << _name << " has no more power..\n";
		std::cout << "( Message ) " << _name << ": Sorry.. I can't attack anymore..\n\n" << EOC;
		delete this;
	}
	else {
		_energy -= 1;		
		std::cout << _name << " attacks " << target << "!!, causing " << _attackDamage << " points of damage!!\n";
		std::cout << "( Message ) How about FragTrap's Taste???\n" << EOC;
		ClapTrap::showStatus();
	}
}

void FragTrap::highFivesGuys() {
	std::cout << FRAG << "[Cheer Up Request] ";
	if (_energy == 0 || _hit == 0) {
		std::cout << _name << " has no more energy or hit point..\n";
		std::cout << "( Message ) " << _name << ": Sorry.. I can't change mode.. Bye..\n\n" << EOC;
	}
	std::cout << "High Five With " << _name << "! Keep going guys!\n\n" << EOC;
}