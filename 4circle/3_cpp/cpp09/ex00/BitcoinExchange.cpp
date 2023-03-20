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

bool BitcoinExchange::splitAndCheckInput(std::string input) {
	int len = input.length();
	int i;

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
	_value = atof((input.substr(i + 2, len - i - 2)).c_str());
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

bool BitcoinExchange::splitAndCheckDate(std::string date) {
	if (date.length() != 10 || !(date[4] == '-' && date[7] == '-'))
		return false;
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);
	_year = atoi(year.c_str());
	_month = atoi(month.c_str());
	_day = atoi(day.c_str());
	if (!checkValidDate())
		return false;
	std::string tmp;
	tmp.append(year);
	tmp.append(month);
	tmp.append(day);
	_sDate = date;
	_iDate = atoi(tmp.c_str());
	return true;
}

bool BitcoinExchange::checkValidDate() {
	if (_year < 2009 || _year > 2023 || (_year == 2023 && _month > 4))
		return false;
	if (_month < 1 || _month > 12)
		return false;
	if (_day < 0)
		return false;
	if (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12) {
		if (_day > 31)
			return false;
	}
	if (_month == 4 || _month == 6 || _month == 9 || _month == 10) {
		if (_day > 30)
			return false;
	}
	if (_year % 400 == 0 || (_year % 4 == 0 && _year % 100 != 0)) {
		if (_day > 29)
			return false;	
	} else {
		if (_day > 28)
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