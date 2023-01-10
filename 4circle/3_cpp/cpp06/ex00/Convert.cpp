/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:14:15 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/10 20:19:59 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert() {
}

Convert::Convert(std::string& input)
: _input(input), _value(0.0), _flag(true) {}

Convert::Convert(const Convert& obj) {
	*this = obj;
}

Convert& Convert::operator=(const Convert& obj) {
	if (this != &obj)
	{
		_input = obj.getInput();
		_value = obj.getValue();
		_flag = obj.getFlag();
	}
	return (*this);
}

Convert::~Convert() {}

std::string Convert::getInput() const {
	return _input;
}

double Convert::getValue() const {
	return _value;
}

bool Convert::getFlag() const {
	return _flag;
}