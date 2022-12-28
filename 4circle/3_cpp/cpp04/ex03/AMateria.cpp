/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:49:47 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/12/28 17:50:08 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

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

std::string const& AMateria::getType() const {
	return type;
}

void AMateria::use (ICharacter& target) {
	std::cout << AMATERIA << "use amateria\n";
}