/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:02:26 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/10/09 14:49:06 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string name, Weapon &weapon) 
: _name(name), _weapon(weapon)
{
	std::cout << _name << " created. (weapon: " << _weapon.getType() << ")\n";
}

void HumanA::attack() const{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}