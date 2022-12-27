/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:45:59 by hyunjcho          #+#    #+#             */
/*   Updated: 2022/12/27 16:15:10 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "이상한 고양이";
	std::cout << CAT << "안녕, 나는 이상한 고양이야\n\n" << EOC;
}

WrongCat::WrongCat(const WrongCat &obj) {
	*this = obj;
}

WrongCat& WrongCat::operator=(const WrongCat &obj) {
	if (this != &obj)
		type = obj.getType();
	return *this;
}

void WrongCat::makeSound() const{
	std::cout << CAT << "이얏호응\n\n" << EOC;
}

std::string WrongCat::getType() const{
	return type;
}

WrongCat::~WrongCat() {
	std::cout << CAT << "안녕! " << type << "는 이만 간다!\n" << EOC;
}