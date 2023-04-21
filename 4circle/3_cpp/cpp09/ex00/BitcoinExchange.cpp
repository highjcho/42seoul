/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:00:20 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/04/21 13:19:24 by hyunjcho         ###   ########.fr       */
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
		_date = obj._date;
		_value = obj._value;
		_year = obj._year;
		_month = obj._month;
		_day = obj._day;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}


bool BitcoinExchange::checkValidDate() {
	time_t timer = time(NULL);
	struct tm* t = localtime(&timer);
	if (_year > 2023 || (_year == 2023 && (_month > t->tm_mon + 1 || (_month == t->tm_mon + 1 && _day > t->tm_mday))))
		return (false);
	if (_month < 1 || _month > 12 || _day < 1 || _day > 31)
		return (false);
	if (_month == 2) {
		if ((_year % 400 == 0 || (_year % 4 == 0 && _year % 100 != 0)) && _day < 30)
			return (true);
		else if (_day > 28)
			return (false);
	}
	else if ((_month == 4 || _month == 6 || _month == 9 || _month == 11) && _day > 30)
		return (false);
	return (true);
}

bool BitcoinExchange::convertDate(std::string const& date) {
	std::stringstream ss(date);
	ss >> _year;
	if (ss.get() != '-' || !std::isdigit(ss.peek()))
		return (false);
	ss >> _month;
	if (ss.get() != '-' || !std::isdigit(ss.peek()))
		return (false);
	ss >> _day;
	if (!ss.eof())
		return (false);
	return (true);
}

bool BitcoinExchange::splitAndCheckDate(std::string const& date) {
	if (date.length() != 10)
		return (false);
	if (!convertDate(date))
		return (false);
	if (!checkValidDate())
		return (false);
	return (true);
}

bool BitcoinExchange::splitAndCheckInput(std::string const& input) {
	int len = input.length();
	int i;
	char* end;

	for (i = 0; i < len; i++) {
		if (input[i] == '|')
			break;
	}
	if (i == len || len < 14 || input[i - 1] != ' ' || input[i + 1] != ' ') {
		std::cerr << "Error: bad input => " << input << std::endl;
		return (false);
	}
	_date = input.substr(0, i - 1);
	if (!splitAndCheckDate(_date)) {
		std::cerr << "Error: bad input => " << input << std::endl;
		return (false);
	}
	end = NULL;
	_value = strtod((input.substr(i + 2)).c_str(), &end);
	if (*end != '\0') {
		std::cerr << "Error: bad input => " << input << std::endl;
		return (false);
	}
	if (_value < 0) {
		std::cerr << "Error: not a positive number.\n";
		return (false);
	}
	if (_value > 1000) {
		std::cerr << "Error: too large a number.\n";
		return (false);
	}
	return (true);
}

std::string BitcoinExchange::getDate() const {
	return _date;
}

double BitcoinExchange::getValue() const {
	return _value;
}