/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:40:09 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/12/28 18:42:04 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() {
	name = "Cure";
	std::cout << CURE << "[Create] Cure Materia\n\n" << EOC;
}

AMateria* Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter& target) {
	std::cout << CURE << "* heals " << target.getName() << "'s wounds *\n\n" << EOC;
}

Cure::~Cure() {
	std::cout << CURE << "[Destroy] Cure\n\n" << EOC;
}