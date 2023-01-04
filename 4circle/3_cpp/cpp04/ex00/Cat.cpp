/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:45:59 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/04 11:44:21 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << CAT << "안녕, 나는 고양이야\n\n" << EOC;
}

Cat::Cat(const Cat &obj) {
	*this = obj;
}

Cat& Cat::operator=(const Cat &obj) {
	if (this != &obj)
		type = obj.getType();
	return *this;
}

void Cat::makeSound() const{
	std::cout << CAT << "야옹야옹\n\n" << EOC;
}

Cat::~Cat() {
	std::cout << CAT << "안녕! 고양이는 이만 간다!\n" << EOC;
}
