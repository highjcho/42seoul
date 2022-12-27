/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:51:12 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/12/27 18:36:46 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << ANIMAL << "안녕, 나는 동물이야\n" << EOC;
}

Animal::Animal(const Animal &obj) {
	*this = obj;
}

Animal& Animal::operator=(const Animal &obj) {
	if (this != &obj)
		type = obj.getType();
	return *this;
}

std::string Animal::getType() const{
	return type;
}

Animal::~Animal() {
	std::cout << ANIMAL << "안녕! 동물은 이만 간다!\n\n" << EOC;
}