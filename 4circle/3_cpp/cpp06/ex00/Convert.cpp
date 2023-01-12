/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:14:15 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/12 22:51:00 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert() {
}

Convert::Convert(std::string input)
: _input(input), _flag(false)
{
	char *end = NULL;
	_value = std::strtod(_input.c_str(), &end);
	if (*end && std::strcmp(end, "f"))
		_flag = true;
}

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

char Convert::toChar() {
	if (_input.size() == 1 && std::isprint(_input[0]))
		return static_cast<char>(_input[0]);
	if (_flag)
		throw ImpossibleException();
	if (!std::isprint(_value))
		throw NonDisplayableException();
	return static_cast<char>(_value);
}

int Convert::toInt() {
	if (_input.size() == 1 && std::isprint(_input[0]) && (_input[0] > 57 || _input[0] <48))
		return static_cast<int>(_input[0]);
	if (_flag)
		throw ImpossibleException();
	return static_cast<int>(_value);
}

float Convert::toFloat() {
	if (_input.size() == 1 && std::isprint(_input[0]) && (_input[0] > 57 || _input[0] <48))
		return static_cast<float>(_input[0]);
	if (_flag)
		throw ImpossibleException();
	return static_cast<float>(_value);
}

double Convert::toDouble() {
	if (_input.size() == 1 && std::isprint(_input[0]) && (_input[0] > 57 || _input[0] <48))
		return static_cast<double>(_input[0]);
	if (_flag)
		throw ImpossibleException();
	return static_cast<double>(_value);
}

void Convert::print() {
	Convert::printChar();
	Convert::printInt();
	Convert::printFloat();
	Convert::printDouble();
}

void Convert::printChar() {
	std::cout << "char: ";
	try {
		char c = toChar();
		std::cout << "'" << c << "'" << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void Convert::printInt() {
	std::cout << "int: ";
	try {
		int i = toInt();
		std::cout << i << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void Convert::printFloat() {
	std::cout << "float: ";
	try {
		float f = toFloat();
		if (std::isnan(f) || std::isinf(f)) 
			std::cout << std::showpos << f << "f" << std::endl;
		else if (f != std::floor(f))
			std::cout << f << "f" << std::endl;
		else
			std::cout << f << ".0f" << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void Convert::printDouble() {
	std::cout << "Double: ";
	try {
		double d = toDouble();
		if (std::isnan(d) || std::isinf(d))
			std::cout << std::showpos << d << std::endl;
		else if (d != std::floor(d))
			std::cout << d << std::endl;
		else
			std::cout << d << ".0" << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

std::string Convert::getInput() const {
	return _input;
}

double Convert::getValue() const {
	return _value;
}

bool Convert::getFlag() const {
	return _flag;
}

const char* Convert::ImpossibleException::what() const throw() {
	return "impossible";
}

const char* Convert::NonDisplayableException::what() const throw() {
	return "Non displayable";
}