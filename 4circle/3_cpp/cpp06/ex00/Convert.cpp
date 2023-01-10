/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:14:15 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/10 22:25:57 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert() {
}

Convert::Convert(std::string input)
: _input(input), _flag(false), _isNan(false), _isInf(false)
{
	char *end = NULL;
	_value = std::strtod(_input.c_str(), &end);
	if (*end && std::strcmp(end, "f"))
		_flag = true;
	else {
		if (std::isnan(_value))
			_isNan = true;
		if (std::isinf(_value))
			_isInf = true;
	}
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
		_isNan = obj.getNan();
		_isInf = obj.getInf();
	}
	return (*this);
}

Convert::~Convert() {}

char Convert::toChar() {
	if (_flag || _isNan || _isInf)
		throw ImpossibleException();
	if (!std::isprint(_value))
		throw NonDisplayableException();
	if (_value > CHAR_MAX || _value < CHAR_MIN)
		throw NotInRangeException();
	return static_cast<char>(_value);
}

int Convert::toInt() {
	if (_flag || _isNan || _isInf)
		throw ImpossibleException();
	if (_value > INT_MAX || _value < INT_MIN)
		throw NotInRangeException();
	return static_cast<int>(_value);
}

float Convert::toFloat() {
	if (_flag)
		throw ImpossibleException();
	if (_value > FLT_MAX) // flt_min?
		throw NotInRangeException();
	return static_cast<float>(_value);
}

double Convert::toDouble() {
	if (_flag)
		throw ImpossibleException();
	if (_value > DBL_MAX)
		throw NotInRangeException();
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
		if (_isNan || _isInf)
			std::cout << std::showpos << f << "f" << std::endl;
		else if (std::isinf(f))
			std::cout << std::setprecision(std::numeric_limits<float>::digits10) << toFloat() << std::endl;
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
		float d = toDouble();
		if (_isNan || _isInf)
			std::cout << std::showpos << d << std::endl;
		else if (std::isinf(d))
			std::cout << std::setprecision(std::numeric_limits<double>::digits10) << toDouble() << std::endl;
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

bool Convert::getNan() const {
	return _isNan;
}

bool Convert::getInf() const {
	return _isInf;
}

const char* Convert::ImpossibleException::what() const throw() {
	return "impossible";
}

const char* Convert::NonDisplayableException::what() const throw() {
	return "Non displayable";
}

const char* Convert::NotInRangeException::what() const throw() {
	return "Not in normal range";
}