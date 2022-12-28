/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:56:20 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/12/28 17:56:04 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {
	_quantity = 0;
	std::cout << CHARACTER << "[CREATE] Chracter\n\n" << EOC; 
}

Character::Character(const std::string name) {
	_name = name;
	std::cout << CHARACTER << "[LOGIN] HI, I'm " << _name << "\n\n" << EOC; 
}

Character::Character(const Character &obj) {
	*this = obj;
}

Character& Character::operator=(const Character &obj) {
	if (this != &obj)
		_name = obj.getName();
	return *this;
}

std::string const& Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	std::cout << CHARACTER << "[EQUIP] " << _name;
	if (_quantity == SLOT) {
		std::cout << "'s inventory is full!\n\n" << EOC;
		return ;
	}
	_inventory[Character::findIdx()] = m;
	_quantity++;
	std::cout << " has " << m->getType() << "!\n\n" << EOC;
}

void Character::unequip(int idx) {
	std::cout << CHARACTER << "[UNEQUIP] " << _name;
	if (_quantity == 0) {
		std::cout << " doesn't have any materia yet\n\n" << EOC;
		return ;
	}
	if (_inventory[idx] == NULL) {
		std::cout << " doesn't have materia in this slot\n\n" << EOC;
		return ;
	}
	std::cout << " drop the " << _inventory[idx]->getType() << " materia\n\n" << EOC;
	_inventory[idx] = NULL;
	_quantity--;
}

void Character::use(int idx, ICharacter& target) {
	std::cout << CHARACTER << "[USE] " << _name;
	if (_quantity == 0) {
		std::cout << " doesn't have any materia yet\n\n" << EOC;
		return ;
	}
	if (_inventory[idx] == NULL) {
		std::cout << " doesn't have materia in this slot\n\n" << EOC;
		return ;
	}
	_inventory[idx]->use(target);
}

int Character::findIdx() {
	for (int i = 0; i < SLOT; i++) {
		if (_inventory[i] == NULL)
			return i;
	}
}

void Character::showMateriaStatus() {
	std::cout << CHARACTER << "[ " << _name << "'s inventory ]\n\n";
	for (int i = 0; i < SLOT; i++) {
		std::cout << "- slot [" << i << "] : ";
		if (_inventory[i] != NULL)
			std::cout << _inventory[i]->getType() << "\n";
		else
			std::cout << "empty\n";
	}
	std::cout << EOC << std::endl;
}