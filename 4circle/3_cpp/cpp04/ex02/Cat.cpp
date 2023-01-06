/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:45:59 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/06 11:59:57 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : _brain(new Brain())
{
	type = "고양이";
	std::cout << CAT << "안녕, 나는 고양이야\n\n" << EOC;
}

Cat::Cat(const Cat &obj) {
	*this = obj;
}

Cat& Cat::operator=(const Cat &obj) {
	if (this != &obj) {
		type = obj.getType();
		_brain = new Brain(*obj.getBrain());
	}
	return *this;
}

void Cat::makeSound() const{
	std::cout << CAT << "야옹야옹\n\n" << EOC;
}

std::string Cat::getType() const{
	return type;
}

Brain* Cat::getBrain() const {
	return _brain;
}

Cat::~Cat() {
	delete _brain;
	std::cout << CAT << "안녕! " << type << "는 이만 간다!\n" << EOC;
}
