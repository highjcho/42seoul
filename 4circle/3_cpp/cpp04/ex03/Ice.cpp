/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:50:25 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/02 19:37:13 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() {
	name = "Ice";
	type = "ice";
	std::cout << ICE << "[Create] Ice Materia\n\n" << EOC;
}

AMateria* Ice::clone() const {
	return new Ice();
}

void Ice::use(ICharacter& target) {
	std::cout << ICE << "* shoots an ice bolt at " << target.getName() << " *\n\n" << EOC;
}

Ice::~Ice() {
	std::cout << ICE << "[Destroy] Ice\n\n" << EOC;
}