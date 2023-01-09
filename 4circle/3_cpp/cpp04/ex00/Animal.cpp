/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:51:12 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/09 16:11:36 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("동물")
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

void Animal::makeSound() const {
	std::cout << ANIMAL << "동물동물\n\n" << EOC;
}

std::string Animal::getType() const{
	return type;
}

Animal::~Animal() {
	std::cout << ANIMAL << "안녕! 동물은 이만 간다!\n\n" << EOC;
}