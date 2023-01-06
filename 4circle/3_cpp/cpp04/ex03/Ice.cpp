/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:50:25 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/06 17:22:49 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() {
	type = "ice";
	std::cout << ICE << "[Create] Ice Materia\n\n" << EOC;
}

Ice::Ice(const Ice &obj) {
	*this = obj;
}

Ice& Ice::operator=(const Ice &obj) {
	if (this != &obj)
		type = obj.getType();
	return *this;
}

AMateria* Ice::clone() const {
	return new Ice();
}

void Ice::use(ICharacter& target) {
	std::cout << ICE << "* shoots an ice bolt at " << target.getName() << " *\n\n" << EOC;
}

Ice::~Ice() {
	std::cout << ICE << "[Destroy] Ice\n" << EOC;
}