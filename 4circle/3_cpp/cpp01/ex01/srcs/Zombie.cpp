/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:56:20 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/10/09 14:41:05 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie() {
}

Zombie::~Zombie() {
	std::cout << _name << " is died again.\n";
}

void Zombie::setName(const std::string name) {
	_name = name;
}

void Zombie::announce() const {
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}