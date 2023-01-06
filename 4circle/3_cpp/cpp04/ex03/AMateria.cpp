/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:49:47 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/06 17:23:09 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : type("AMateria") {
	std::cout << AMATERIA << "[Create] AMateria\n" << EOC;
}

AMateria::AMateria(std::string const& type) : type(type) {
	std::cout << AMATERIA << "[Create] AMateria - type: " << type << EOC << std::endl;
}

AMateria::AMateria(const AMateria &obj) {
	*this = obj;
}

AMateria& AMateria::operator=(const AMateria &obj) {
	if (this != &obj)
		type = obj.getType();
	return *this;
}

AMateria::~AMateria() {
	std::cout << AMATERIA << "[Destroy] AMateria\n\n" << EOC;
}

std::string const& AMateria::getType() const {
	return type;
}

void AMateria::use (ICharacter& target) {
	std::cout << AMATERIA << "use amateria at " << target.getName();
}