/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:24:25 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/12/27 16:45:47 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << ANIMAL << "안녕, 나는 이상한 동물이야\n" << EOC;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj) {
	*this = obj;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &obj) {
	if (this != &obj)
		type = obj.getType();
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << ANIMAL << "물동물동\n\n" << EOC;
}

std::string WrongAnimal::getType() const{
	return type;
}

WrongAnimal::~WrongAnimal() {
	std::cout << ANIMAL << "안녕! 이상한 동물은 이만 간다!\n\n" << EOC;
}