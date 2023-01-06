/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:24:11 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/06 17:39:53 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < SLOT; i++)
		_materias[i] = NULL;
	_quantity = 0;
	std::cout << SOURCE << "[Create] MateriaSource\n\n" << EOC;
}

MateriaSource::MateriaSource(const MateriaSource &obj) {
	*this = obj;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &obj) {
	if (this != &obj) {
		for (int i = 0; i < SLOT; i++) {
			if (_materias[i]) {
				delete _materias[i];
				_materias[i] = NULL;
			}
			AMateria* materia = obj.getMateria(i);
			if (materia)
				_materias[i] = materia->clone();
		}
		_quantity = obj.getQuantity();
	}
	std::cout << SOURCE << "[Create] Source COPY\n\n" << EOC; 
	return *this;
}

void MateriaSource::learnMateria(AMateria* materia) {
	if (!materia) {
		std::cout << "[Error] Materia is null\n";
		return ;
	}
	if (_quantity == SLOT) {
		std::cout << "[Error] MateriaSource is full \n\n";
		return ;
	}
	_materias[_quantity] = materia;
	_quantity++;
	std::cout << SOURCE << "[Learn Materia] You can use a " << materia->getType() << "\n\n" << EOC;
}


AMateria* MateriaSource::createMateria(std::string const& type) {
	AMateria* materia = MateriaSource::findMateria(type);
	if (!materia) {
		std::cout << "[Error] There is no " << type << " meteria\n\n";
		return NULL;
	}
	return materia->clone();
}

AMateria* MateriaSource::getMateria(const int i) const {
	return _materias[i];
}

int MateriaSource::getQuantity() const {
	return _quantity;
}

AMateria* MateriaSource::findMateria(std::string const& type) {
	if (_quantity == 0)
		return NULL;
	for (int i = 0; i < _quantity; i++) {
		if (_materias[i]->getType() == type)
			return _materias[i];
	}
	return NULL;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < SLOT; i++) {
		if (_materias[i])
			delete _materias[i];
	}
	std::cout << SOURCE << "[Destroy] MateriaSource\n\n" << EOC;
}