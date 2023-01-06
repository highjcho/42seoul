/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:56:20 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/06 17:41:08 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {
	for (int i = 0; i < SLOT; i++)
		_inventory[i] = NULL;
	_quantity = 0;
	std::cout << CHARACTER << "[Create] Chracter\n\n" << EOC; 
}

Character::Character(const std::string &name) {
	_name = name;
	for (int i = 0; i < SLOT; i++)
		_inventory[i] = NULL;
	_quantity = 0;
	std::cout << CHARACTER << "[Login] HI, I'm " << _name << "\n\n" << EOC; 
}

Character::Character(const Character &obj) {
	*this = obj;
}

Character& Character::operator=(const Character &obj) {
	if (this != &obj) {
		_name = obj.getName();
		for (int i = 0; i < SLOT; i++) {
			if (_inventory[i]) {	
				delete _inventory[i];
				_inventory[i] = NULL;
			}
			AMateria* materia = obj.getMateria(i);
			if (materia)
				_inventory[i] = materia->clone();
		}
		_quantity = obj.getQuantity();
	}
	std::cout << CHARACTER << "[Create] Chracter COPY\n\n" << EOC; 
	return *this;
}

void Character::equip(AMateria* m) {
	if (!m) {
		std::cout << "[Error] Materia is null\n";
		return ;
	}
	std::cout << CHARACTER << "[Equip] " << _name;
	if (_quantity == SLOT) {
		std::cout << "'s inventory is full!\n\n" << EOC;
		return ;
	}
	_inventory[Character::findIdx()] = m;
	_quantity++;
	std::cout << " has a " << m->getType() << "!\n\n" << EOC;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > SLOT) {
		std::cout << "[Error] You got the wrong number\n\n";
		return ;
	}
	std::cout << CHARACTER << "[Unequip] " << _name;
	if (_quantity == 0) {
		std::cout << " doesn't have any materia yet\n\n" << EOC;
		return ;
	} else if (_inventory[idx] == NULL) {
		std::cout << " doesn't have materia in slot " << idx << "\n\n" << EOC;
		return ;
	}
	std::cout << " drop the " << _inventory[idx]->getType() << " materia\n\n" << EOC;
	_inventory[idx] = NULL;
	_quantity--;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > SLOT) {
		std::cout << "[Error] You got the wrong number\n\n";
		return ;
	}
	std::cout << CHARACTER << "[Use] " << _name << " ";
	if (_quantity == 0) {
		std::cout << "doesn't have any materia yet\n\n" << EOC;
		return ;
	} else if (_inventory[idx] == NULL) {
		std::cout << "doesn't have materia in slot " << idx << "\n\n" << EOC;
		return ;
	}
	_inventory[idx]->use(target);
}

int Character::findIdx() {
	int i;
	for (i = 0; i < SLOT; i++) {
		if (_inventory[i] == NULL)
			break;
	}
	return i;
}

void Character::showMateriaStatus() {
	std::cout << CHARACTER << "[ " << _name << "'s inventory ]\n\n";
	for (int i = 0; i < SLOT; i++) {
		std::cout << "- slot [" << i << "] : ";
		if (_inventory[i])
			std::cout << _inventory[i]->getType() << "\n";
		else
			std::cout << "empty\n";
	}
	std::cout << EOC << std::endl;
}

std::string const& Character::getName() const {
	return _name;
}

AMateria* Character::getMateria(const int i) const {
	return _inventory[i];
}

int Character::getQuantity() const {
	return _quantity;
}

Character::~Character() {
	for (int i = 0; i < SLOT; i++) {
		if (_inventory[i])
			delete _inventory[i];
	}
	std::cout << "[Destroy] character\n\n";
}