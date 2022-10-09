/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:02:17 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/10/09 14:55:04 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {
}

Weapon::Weapon(const std::string type) {
	_type = type;
}

std::string Weapon::getType() const{
	return _type;
}

void Weapon::setType(const std::string type) {
	_type = type;
}