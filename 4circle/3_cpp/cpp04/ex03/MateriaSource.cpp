/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:24:11 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/02 19:37:12 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < SLOT; i++)
		_materias[i] = NULL;
	_quantity = 0;
	std::cout << "[Create] MateriaSource\n\n";
}

void MateriaSource::learnMateria(AMateria* materia) {
	if (_quantity == SLOT) {
		std::cout << "[ERROR] MateriaSource is full \n\n";
		return ;
	}
	_materias[_quantity] = materia->clone();
	_quantity++;
	std::cout << "[Learn Materia] You can use a " << materia->getType() << "\n\n";
}

AMateria* MateriaSource::findMateria(std::string const& type) {
	if (_quantity == 0)
		return NULL;
	for (int i = 0; i < _quantity; i++) {
		if (_materias[i]->getType().compare(type) == 0)
			return _materias[i];
	}
	return NULL;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	AMateria* materia = MateriaSource::findMateria(type);
	if (!materia) {
		std::cout << "[ERROR] There is no " << type << "meteria\n\n";
		return NULL;
	}
	return materia->clone();
}

MateriaSource::~MateriaSource() {
	std::cout << "[DELETE] MateriaSource\n\n";
}