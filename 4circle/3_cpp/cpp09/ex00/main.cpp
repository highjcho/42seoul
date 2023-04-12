/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:00:29 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/04/12 14:55:34 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <map>

bool checkDateFormat(std::string &date) {
	std::stringstream ss(date);
	int tmp;
	ss >> tmp;
	if (ss.get() != '-' || !std::isdigit(ss.peek()))
		return false;
	ss >> tmp;
	if (ss.get() != '-' || !std::isdigit(ss.peek()))
		return false;
	ss >> tmp;
	if (!ss.eof())
		return false;
	return true;
}

int stringToInt(std::string date) {
	if (date.length() < 10)
		return (-1);
	if (!checkDateFormat(date))
		return (-1);
	std::stringstream ss;
	int ret;
	ss << date.substr(0, 4) << date.substr(5, 2) << date.substr(8, 2);
	ss >> ret;
	return(ret);
}

void makeDBMap(std::map<int, double> &db) {
	std::ifstream data("data.csv");
	std::string line;
	int i, len, date;
	double value;
	char* end = NULL;

	if (data.fail()) {
		std::cerr << "Error: can't open database\n";
		exit(EXIT_FAILURE);
	}
	std::getline(data,line);
	while (std::getline(data, line)) {
		len = line.length();
		for (i = 0; i < len; i++) {
			if (line[i] == ',')
				break;
		}
		date = stringToInt(line.substr(0, i));
		value = strtod((line.substr(i + 1, len - i - 1)).c_str(), &end);
		if (date == -1 || *end != '\0') {
			std::cerr << "Error: Database has error date" << std::endl;
			data.close();
			exit(EXIT_FAILURE);
		}
		db.insert(std::make_pair(date, value));
	}
	data.close();
}

std::map<int,double>::iterator findPrice(std::map<int, double> &db, int date) {
	std::map<int, double>::iterator iter;

	if (db.begin()->first > date) {
		std::cerr << "Error: cannot find the lower date\n";
		return db.end();
	}
	iter = db.lower_bound(date);
	if (iter == db.end() || iter->first != date)
		iter--;
	return iter;
}

int	main(int ac, char **av) {
	BitcoinExchange bitcoinExchanger;
	std::map<int, double> db;
	std::map<int, double>::iterator iter;
	std::string line;

	if (ac != 2) {
		std::cerr << "Error: could not open file.\n";
		exit(EXIT_FAILURE);
	}
	std::ifstream inputFile(av[1]);
	if (inputFile.fail()) {
		std::cerr << "Error: could not open file.\n";
		exit(EXIT_FAILURE);
	}
	makeDBMap(db);
	int i = 0;
	while (std::getline(inputFile, line)) {
		if (i == 0 && line == "date | value")
			std::getline(inputFile, line);
		if (!bitcoinExchanger.splitAndCheckInput(line))
			continue;
		iter = findPrice(db, bitcoinExchanger.getIDate());
		if (iter != db.end()) {
			std::cout << bitcoinExchanger.getSDate() << " => " << bitcoinExchanger.getValue() << " = " << \
				iter->second * bitcoinExchanger.getValue() << std::endl;
		}
		i++;
	}
	inputFile.close();
}