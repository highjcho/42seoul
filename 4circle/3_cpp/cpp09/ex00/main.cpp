/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:00:29 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/04/19 13:11:59 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <map>

bool checkDateFormat(std::string const& date) {
	if (date.length() != 10)
		return (false);
	std::stringstream ss(date);
	int tmp;
	ss >> tmp;
	if (ss.get() != '-' || !std::isdigit(ss.peek()))
		return (false);
	ss >> tmp;
	if (ss.get() != '-' || !std::isdigit(ss.peek()))
		return (false);
	ss >> tmp;
	if (!ss.eof())
		return (false);
	return (true);
}

void makeDBMap(std::map<std::string, double> &db) {
	std::ifstream data("data.csv");
	std::string line;
	int i, len;
	double value;

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
		std::string date = line.substr(0, i);
		char* end = NULL;
		value = strtod((line.substr(i + 1)).c_str(), &end);
		if (!checkDateFormat(date) || *end != '\0') {
			std::cerr << "Error: Database has error date" << std::endl;
			data.close();
			exit(EXIT_FAILURE);
		}
		db.insert(std::make_pair(date, value));
	}
	data.close();
}

std::map<std::string,double>::iterator findPrice(std::map<std::string, double> &db, std::string date) {
	std::map<std::string, double>::iterator iter;

	if (db.begin()->first > date) {
		std::cout << date << " date\n";
		std::cerr << "Error: cannot find the lower date\n";
		return db.end();
	}
	iter = db.lower_bound(date);
	if (iter == db.end() || iter->first != date) {
		iter--;
	}
	return iter;
}

int	main(int ac, char **av) {
	BitcoinExchange bitcoinExchanger;
	std::map<std::string, double> db;
	std::map<std::string, double>::iterator iter;
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
		iter = findPrice(db, bitcoinExchanger.getDate());
		if (iter == db.end())
			continue;
		std::cout << bitcoinExchanger.getDate() << " => " << bitcoinExchanger.getValue() << " = " << \
			iter->second * bitcoinExchanger.getValue() << std::endl;
		i++;
	}
	inputFile.close();
}