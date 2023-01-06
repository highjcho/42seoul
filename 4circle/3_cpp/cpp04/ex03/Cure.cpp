/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:40:09 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/06 17:22:42 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() {
	type = "cure";
	std::cout << CURE << "[Create] Cure Materia\n\n" << EOC;
}

Cure::Cure(const Cure &obj) {
	*this = obj;
}

Cure& Cure::operator=(const Cure &obj) {
	if (this != &obj)
		type = obj.getType();
	return *this;
}

Cure::~Cure() {
	std::cout << CURE << "[Destroy] Cure\n" << EOC;
}

AMateria* Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter& target) {
	std::cout << CURE << "* heals " << target.getName() << "'s wounds *\n\n" << EOC;
}