/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:00:20 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/04/12 15:01:51 by hyunjcho         ###   ########.fr       */
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
	time_t timer = time(NULL);
	struct tm* t = localtime(&timer);
	if (_year > 2023 || (_year == 2023 && (_month > t->tm_mon + 1 || (_month == t->tm_mon + 1 && _day > t->tm_mday))))
		return false;
	if (_month < 1 || _month > 12 || _day < 1 || _day > 31)
		return false;
	if (_month == 2) {
		if ((_year % 400 == 0 || (_year % 4 == 0 && _year % 100 != 0)) && _day > 29)
			return false;
		else if (_day > 28)
			return false;
	}
	else if (_month == 4 || _month == 6 || _month == 9 || _month == 11) {
		if (_day > 30)
			return false;
	}
	return true;
}

bool BitcoinExchange::convertDate(std::string &date) {
	std::stringstream ss(date);
	ss >> _year;
	if (ss.get() != '-' || !std::isdigit(ss.peek()))
		return false;
	ss >> _month;
	if (ss.get() != '-' || !std::isdigit(ss.peek()))
		return false;
	ss >> _day;
	if (!ss.eof())
		return false;
	return true;
}

bool BitcoinExchange::splitAndCheckDate(std::string date) {
	if (date.length() != 10)
		return false;
	if (!convertDate(date))
		return false;
	if (!checkValidDate())
		return false;
	_sDate = date;
	std::stringstream ss;
	ss << date.substr(0, 4) << date.substr(5, 2) << date.substr(8, 2);
	ss >> _iDate;
	return true;
}

bool BitcoinExchange::splitAndCheckInput(std::string input) {
	int len = input.length();
	int i;
	char* end;

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