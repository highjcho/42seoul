/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:48:30 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/04 11:44:59 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
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

Dog::~Dog() {
	std::cout << DOG << "안녕! 강아지는 이만 간다!\n" << EOC;
}