/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:37:32 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/03/21 17:29:01 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& obj) {
	*this = obj;
}

RPN& RPN::operator=(const RPN& obj) {
	if (this != &obj)
	{
		_formular = obj.getFormular();
	}
	return (*this);
}

RPN::~RPN() {}

int RPN::calculator(char f) {
	if (f == '+') 
		return _b + _a;
	if (f == '-')
		return _b - _a;
	if (f == '*')
		return _b * _a;
	return _b / _a;
}

void RPN::makeStack(std::string input) {
	for (size_t i = 0; i < input.length(); i++) {
		if (input[i] - '0' >= 0 && input[i] - '0' <= 9)
			_formular.push(input[i] - '0');
		else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
			if (_formular.size() >= 2) {
				_a = _formular.top();
				_formular.pop();
				_b = _formular.top();
				_formular.pop();
				_formular.push(calculator(input[i]));
			} else {
				std::cerr << "Error\n";
				exit(EXIT_FAILURE);
			}
		} else if (input[i] == ' ')
			continue;
		else {
			std::cerr << "Error\n";
			exit(EXIT_FAILURE);
		}
	}
}

std::stack<int> RPN::getFormular() const {
	return _formular;
}