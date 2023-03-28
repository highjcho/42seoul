/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:37:32 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/03/28 17:45:05 by hyunjcho         ###   ########.fr       */
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
		_a = obj.getA();
		_b = obj.getB();
	}
	return (*this);
}

RPN::~RPN() {}

int RPN::calculator(char f) {
	if (f == '+') 
		return _a + _b;
	if (f == '-')
		return _a - _b;
	if (f == '*')
		return _a * _b;
	if (_b == 0)
		throw ZeroDivisionException();
	return _a / _b;
}

void RPN::makeStack(std::string input) {
	int tmp;

	for (size_t i = 0; i < input.length(); i++) {
		if (input[i] - '0' >= 0 && input[i] - '0' <= 9)
			_formular.push(input[i] - '0');
		else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
			if (_formular.size() >= 2) {
				_b = _formular.top();
				_formular.pop();
				_a = _formular.top();
				_formular.pop();
				try {
					tmp = calculator(input[i]);
				} catch (std::exception& e) {
					std::cout << e.what() << "\n";
					exit(EXIT_FAILURE);
				}
				_formular.push(tmp);
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

int RPN::getA() const {
	return _a;
}

int RPN::getB() const {
	return _b;
}

const char* RPN::ZeroDivisionException::what() const throw() {
	return "Error";
}