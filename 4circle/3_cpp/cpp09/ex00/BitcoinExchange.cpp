/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:00:20 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/04/03 20:14:36 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj) {
	*this = obj;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj) {
	if (this != &obj)
	{
		_sDate = obj.getSDate();
		_iDate = obj.getIDate();
		_value = obj.getValue();
		_year = obj.getYear();
		_month = obj.getMonth();
		_day = obj.getDay();
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}


bool BitcoinExchange::checkValidDate() {
	
	if (_year > 2023 || (_year == 2023 && _month > 3))
		return false;
	if (_month < 1 || _month > 12)
		return false;
	if (_day < 1)
		return false;
	if ((_month < 8 && _month % 2 == 1) || (_month > 7 && _month % 2 == 0)) {
		if (_day > 31)
			return false;
	}
	else if ((_month > 3 && _month % 2 == 0) || (_month % 2 == 1)) {
		if (_day > 30)
			return false;
	}
	else if (_year % 400 == 0 || (_year % 4 == 0 && _year % 100 != 0)) {
		if (_day > 29)
			return false;
	} else {
		if (_day > 28)
			return false;
	}
	return true;
}

bool BitcoinExchange::splitAndCheckDate(std::string date) {
	if (date.length() != 10 || !(date[4] == '-' && date[7] == '-'))
		return false;

	std::stringstream ss; // 여기만 정리.

	ss << date.substr(0, 4);
	ss >> _year;
	ss.clear();
	ss << date.substr(5, 2);
	ss >> _month;
	ss.clear();
	ss << date.substr(8, 2);
	ss >> _day;
	if (!checkValidDate())
		return false;
	_sDate = date;
	ss.clear();
	ss << date.substr(0, 4) << date.substr(5, 2) << date.substr(8, 2);
	std::string tmp;
	ss >> tmp;
	_iDate = std::strtod(tmp.c_str(), NULL); // 에러처리
	return true;
}

bool BitcoinExchange::splitAndCheckInput(std::string input) {
	int len = input.length();
	int i;
	char *end;

	for (i = 0; i < len; i++) {
		if (input[i] == '|')
			break;
	}
	if (i == len || len < 14 || input[i - 1] != ' ' || input[i + 1] != ' ') {
		std::cerr << "Error: bad input => " << input << std::endl;
		return false;
	}
	if (!splitAndCheckDate(input.substr(0, i - 1))) {
		std::cerr << "Error: bad input => " << input << std::endl;
		return false;
	}
	end = NULL;
	_value = strtod((input.substr(i + 2, len - i - 2)).c_str(), &end);
	if (*end != '\0') {
		std::cerr << "Error: bad input => " << input << std::endl;
		return false;
	}
	if (_value < 0) {
		std::cerr << "Error: not a positive number.\n";
		return false;
	}
	if (_value > 1000) {
		std::cerr << "Error: too large a number.\n";
		return false;
	}
	return true;
}

std::string BitcoinExchange::getSDate() const {
	return _sDate;
}

int BitcoinExchange::getIDate() const {
	return _iDate;
}

double BitcoinExchange::getValue() const {
	return _value;
}

int BitcoinExchange::getYear() const {
	return _year;
}

int BitcoinExchange::getMonth() const {
	return _month;
}

int BitcoinExchange::getDay() const {
	return _day;
}