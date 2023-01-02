/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:40:09 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/02 19:35:12 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() {
	name = "Cure";
	type = "cure";
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