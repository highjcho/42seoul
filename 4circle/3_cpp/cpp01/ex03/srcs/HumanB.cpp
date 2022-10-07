/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:02:23 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/10/07 16:02:24 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
: _name(name), _weapon(NULL)
{
	std::cout << _name << " created. (Weapon: none)\n";
}

void HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}

void HumanB::attack() {
	if (!_weapon)
		std::cout << _name << " doesn' have a weapon yet!!!\n";
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}