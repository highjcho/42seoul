/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:48:30 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/12/27 16:53:40 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type = "강아지";
	std::cout << DOG << "안녕, 나는 강아지야\n\n" << EOC;
}

Dog::Dog(const Dog &obj) {
	*this = obj;
}

Dog& Dog::operator=(const Dog &obj) {
	if (this != &obj)
		type = obj.getType();
	return *this;
}

void Dog::makeSound() const{
	std::cout << DOG << "멍멍\n\n" << EOC;
}

std::string Dog::getType() const{
	return type;
}

Dog::~Dog() {
	std::cout << DOG << "안녕! " << type << "는 이만 간다!\n" << EOC;
}