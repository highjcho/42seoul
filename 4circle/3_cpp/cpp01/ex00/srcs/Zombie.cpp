/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:55:57 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/10/09 14:37:51 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(const std::string name) {
	_name = name;
}

Zombie::~Zombie() {
	std::cout << _name << " is died again.\n";
}

void Zombie::announce() const {
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}